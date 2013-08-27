#ifndef console_hpp
#define console_hpp

#include <iostream>
#include <string>
#include <sstream>
#include <game_globals/config.hpp>
#include <game_globals/drawer/drawer.hpp>
#include <game_globals/console/console_data_grabber.hpp>

class windowConsole;

namespace _private
{
    class windowConsoleBackGround : public extend::drawable
    {
    friend class windowConsole;

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
        std::cout << "entering" << std::endl;
        startup();
        bool exit = false;
        sf::RenderWindow *Win = game_state::config::getConfig().getWindow();
        sf::Clock timer;
        std::string command;
        while( game_state::config::getConfig().getRunning() )
        {
            sf::Event Event;
            while( Win->pollEvent( Event ) )
            {
                if( Event.type == sf::Event::Closed )
                    game_state::config::getConfig().goOff();

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

            if( exit )
            {
                cleanup();
                break;
            }

            std::cout << "poll finished" << std::endl;
            if( timer.getElapsedTime().asSeconds() > 5 )
            {
                timer.restart();
                std::cout << "still alive~" << std::endl;
            }

            drawer::getDrawer().draw();
        }
        std::cout << "exciting" << std::endl;
    };

private:
    void inputCommand( const std::string & command )
    {
        std::string result;



        logs.push_back( result );
    };

    void cleanup()
    {

    };

    void startup()
    {
        sf::RenderWindow * Win = game_state::config::getConfig().getWindow();
    };

    std::vector< std::string > logs;
    _private::windowConsoleBackGround _bg;
};
#endif // console_hpp
