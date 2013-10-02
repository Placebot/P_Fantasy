#ifndef console_hpp
#define console_hpp

#include <iostream>
#include <string>
#include <sstream>
#include <gameGlobals/config.hpp>
#include <gameGlobals/drawer/drawer.hpp>
#include <gameGlobals/console/consoleDataGrabber.hpp>

#include <gameGlobals/extend.hpp>

#include <resourceBank/resourcesConsole.hpp>

namespace console
{
    class windowConsole;
}

namespace _private
{
    class windowConsoleBackGround : public extend::drawable
    {
    friend class console::windowConsole;

    virtual void draw( sf::RenderWindow &Win )
    {
        if( activated )
            Win.draw( _me );
    };
    void load()
    {

    };

    sf::Sprite _me;
    sf::Texture _meT;
    bool activated = false;
    };
}

namespace console
{
    void consoleActivation( sf::Event & event );

    class resources : public extend::drawable
    {
    public:
        resources()
        {

        };
        ~resources() {};

        sf::Sprite & getSprite( const std::string & key ) { return _sprites[ _fitKey( key ) ]; };
        sf::Text & operator[]( unsigned int & i ) { return _texts[i]; };

        void update( std::string writing )
        {
            _writingAtm.setString( writing );
        };

    private:

        unsigned int _fitKey( const std::string & key )
        {
            for( unsigned int i = 0; i < _keys_spr.size(); i++ )
            {
                if( key == _keys_spr[i] )
                    return i;
            }
        };

        std::vector< sf::Sprite > _sprites;
        std::vector< std::string > _keys_spr;

        std::vector< sf::Text > _texts;
        sf::Text _writingAtm;
    };

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
