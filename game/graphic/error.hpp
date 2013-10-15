#ifndef error_hpp
#define error_hpp

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include <SFML/Graphics.hpp>

#include <gameGlobals/gameGlobals.hpp>
#if defined PF_OUTPUT_DEBUG_GAME_CONSOLE
    #include <gameGlobals/console/consoleDataGrabber.hpp>
#endif

namespace gui
{
    class error
    {
    private:
        ~error() {};
        error() {};
        error * operator=( const error & ) {};
        error(const error &) {};
    public:
        static void occured( const std::string text, const std::string titlePart = "none", const std::string programPart = "none" )
        {
            while( gameState::config::getConfig().getRunning() )
            {

            }

        };

    private:
        std::vector< sf::Texture > _textures;
        std::vector< sf::Sprite > _sprites;
    };
}

#endif // error_hpp
