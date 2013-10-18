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

#include <graphic/animation/animation.hpp>
#include <gameGlobals/extend.hpp>

namespace gui
{
    class error : public extend::drawable, public animateable
    {
    private:
        ~error() {};
        error() {};
        error * operator=( const error & ) {};
        error(const error &) {};
    public:
        static error & getError() { static error instance; return instance; };

        void occured( const std::string text, const std::string titlePart = "none", const std::string programPart = "none" )
        {
            while( gameState::config::getConfig().getRunning() )
            {

            }
        };

        virtual void update()
        {

        };

        virtual void startAnimation()
        {

        };

        virtual void stopAnimation()
        {

        };

        virtual void pauseAnimation()
        {

        };

        virtual void draw( sf::RenderWindow &Win )
        {

        };

        virtual status getStatus() {  };
    private:
        std::vector< sf::Texture > _textures;
        std::vector< sf::Sprite > _sprites;
    };
}

#endif // error_hpp
