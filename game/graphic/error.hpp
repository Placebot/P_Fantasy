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
    class error : public animateable
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
            drawer::getDrawer().push_back( *this, drawer::topQueue );
            startAnimation();
            while( gameState::config::getConfig().getRunning() )
            {
                while( gameState::config::getConfig().getWindow()->isOpen() )
                {
                    sf::Event event;
                    while( gameState::config::getConfig().getWindow()->pollEvent( event ) )
                    {
                        if( event.type == sf::Event::Closed )
                            gameState::config::getConfig().goOff();
                    }

                    drawer::getDrawer().draw();
                }
            }
            stopAnimation();
        };

        virtual void update()
        {
            if( _myStatus == playing )
            {
                if( _myTimer.getElapsedTime().asSeconds() < _totalAnimationTime )
                {
                    ///----------
                    /// max y = 740
                    /// max x = 540
                    /// 540 -- 3.5
                    /// x --- time
                    ///----------
                    _me.setSize( sf::Vector2f( _myTimer.getElapsedTime().asSeconds()*740/_totalAnimationTime, _myTimer.getElapsedTime().asSeconds()*540/_totalAnimationTime ) );
                    _me.setPosition( gameState::config::getConfig().getWindow()->getSize().x / 2 - _me.getSize().x / 2, gameState::config::getConfig().getWindow()->getSize().y / 2 - _me.getSize().y / 2 );
                }
                else
                    _myStatus = stopped;
            }
        };

        virtual void startAnimation()
        {
            _myTimer.start();
            _myStatus = playing;
        };

        virtual void stopAnimation()
        {
            _myTimer.stop();
            _myStatus = stopped;
        };

        virtual void pauseAnimation()
        {
            _myTimer.pause();
            _myStatus = paused;
        };

        virtual void draw( sf::RenderWindow &Win )
        {
            Win.draw( _me );
            for( unsigned int i = 0; i < _sprites.size(); i++ )
                Win.draw( _sprites[i] );

        };

        virtual status getStatus() { return _myStatus; };
    private:
        std::vector< sf::Texture > _textures;
        std::vector< sf::Sprite > _sprites;

        sf::RectangleShape _me;
        status _myStatus = stopped;
        animationClock _myTimer;

        float _totalAnimationTime = 2.0;
    };
}

#endif // error_hpp
