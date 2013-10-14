#ifndef console_hpp
#define console_hpp

#include <iostream>
#include <string>
#include <sstream>
#include <gameGlobals/config.hpp>
#include <gameGlobals/drawer/drawer.hpp>
#include <gameGlobals/console/consoleDataGrabber.hpp>

#include <gameGlobals/extend.hpp>


namespace console
{
    class windowConsole;
}

namespace _private
{
    class windowConsoleBackGround : public extend::drawable
    {
    friend class console::windowConsole;

    windowConsoleBackGround()
    {
        _me.setFillColor( sf::Color(0,0,0,150) );
        _me.setSize( sf::Vector2f( 400, 300) );
        _me.setPosition(0.0,0.0);
    };

    ~windowConsoleBackGround() {};

    void hide()
    {
        _me.setPosition(-400.0,-300.0);
    };

    void show()
    {
        _me.setPosition(0.0,0.0);
    }

    virtual void draw( sf::RenderWindow &Win )
    {
        if( activated )
            Win.draw( _me );
    };

    sf::RectangleShape _me;
    bool activated = false;
    };

    class drawableLogs : public extend::drawable
    {
    friend class console::windowConsole;

    drawableLogs()
    {

    };

    ~drawableLogs()
    {

    };

    void updateLogs()
    {

    };

    void updatePositions()
    {

    };

    virtual void draw( sf::RenderWindow & Win )
    {
        for( unsigned int i = 0; i < _logs.size(); i++ )
        {
            Win.draw( _logs[i] );
        }
    };

    std::vector< sf::Text > _logs;

    };
}

namespace console
{
    void consoleActivation( sf::Event & event );

    class windowConsole
    {
    private:
        ~windowConsole() {};
        windowConsole() {};
        windowConsole * operator=( const windowConsole & ) {};
        windowConsole(const windowConsole &) {};
    public:
        static windowConsole & getWinConsole() { static windowConsole _instance; return _instance; };

        void boot()
        {
            bool exit = false;
            sf::RenderWindow *Win = gameState::config::getConfig().getWindow();

            drawer::getDrawer().push_back( _bg, drawer::console );

            sf::Clock timer;
            std::string command;
            while( gameState::config::getConfig().getRunning() && !exit )
            {
                sf::Event Event;
                while( Win->pollEvent( Event ) )
                {
                    if( Event.type == sf::Event::Closed )
                        gameState::config::getConfig().goOff();

                    if( Event.type == sf::Event::TextEntered )
                    {
                        if( Event.text.unicode < 128 )
                        {
                            char tempchar = static_cast<char>( Event.text.unicode );
                            std::string quickstring;
                            std::stringstream ss;
                            ss << tempchar;
                            ss >> quickstring;
                            command = command + quickstring;
                        }
                    }

                    if( Event.type == sf::Event::KeyPressed )
                    {
                        if( sf::Keyboard::isKeyPressed( sf::Keyboard::Return ) && command != "" )
                        {
                            inputCommand( command );
                        }
                        else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Tilde ) )
                        {
                            exit = true;
                            break;
                        }
                    }
                }



                std::cout << "poll finished" << std::endl;
                if( timer.getElapsedTime().asSeconds() > 5 )
                {
                    timer.restart();
                    std::cout << "still alive~" << std::endl;
                }

                drawer::getDrawer().draw();
            }
        };

    private:
        void inputCommand( const std::string & command )
        {
            std::string result;



            logs.push_back( result );
        };

        std::vector< std::string > logs;
        _private::windowConsoleBackGround _bg;
    };

}
#endif // console_hpp
