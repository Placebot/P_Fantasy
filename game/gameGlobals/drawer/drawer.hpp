#ifndef drawer_hpp
#define drawer_hpp

#include <iostream>
#include <vector>
#include <gameGlobals/extend.hpp>
#include <gameGlobals/config.hpp>
#include <graphic/animation/animation.hpp>
#include <gameGlobals/topLevelGlobals.hpp>

#if defined PF_OUTPUT_DEBUG_GAME_CONSOLE
    #include <sstream>
#endif

namespace gameState
{
    class config;
}

class drawer
{
private:
    friend class gameState::config;
    ~drawer() {};
    drawer() {};
    drawer * operator=( const drawer & ) {};
    drawer(const drawer &) {};
public:

    enum drawQueue
    {
        normal,
        topQueue,
        console
    };

    static drawer & getDrawer() { static drawer _instance; return _instance; };

    void push_back( extend::drawable & object, const drawQueue qType )
    {
        if( qType == normal )
            toDraw.push_back( &object );
        else if( qType == topQueue )
            toDrawTopLevel.push_back( &object );
        else if( qType == console )
            toDrawConsoleLevel.push_back( &object );
    };

    void remove( extend::drawable & object, const drawQueue qType )
    {
        if( qType == normal )
        {
            if( toDraw.size() )
            {
                for( unsigned int i = 0; i < toDraw.size(); i++ )
                {
                    if( toDraw[i] == &object )
                    {
                        toDraw[i] = NULL;
                        toDraw.erase( toDraw.begin() + i );
                    }
                }
            }
        }
        else if( qType == topQueue )
        {
            if( toDrawTopLevel.size() )
            {
                for( unsigned int i = 0; i < toDrawTopLevel.size(); i++ )
                {
                    if( toDrawTopLevel[i] == &object )
                    {
                        toDrawTopLevel[i] = NULL;
                        toDrawTopLevel.erase( toDrawTopLevel.begin() + i );
                    }
                }
            }
        }
        else if( qType == console )
        {
            if( toDrawConsoleLevel.size() )
            {
                for( unsigned int i = 0; i < toDrawConsoleLevel.size(); i++ )
                {
                    if( toDrawConsoleLevel[i] == &object )
                    {
                        toDrawConsoleLevel[i] = NULL;
                        toDrawConsoleLevel.erase( toDrawConsoleLevel.begin() + i );
                    }
                }
            }
        }
    };

    void draw()
    {
        if( toDraw.size() || toDrawTopLevel.size() || toDrawConsoleLevel.size() )
        {
            #if defined(PF_OUTPUT_DEBUG_C_CONSOLE) || defined(PF_OUTPUT_DEBUG_GAME_CONSOLE)
                sf::Clock DrawTime;
                DrawTime.restart();
            #endif
            sf::RenderWindow * Win = gameState::config::getConfig().getWindow();
            Win->clear();
            for( unsigned int i = 0; i < toDraw.size(); i++ )
            {
                toDraw[i]->draw( *Win );
            }

            for( unsigned int i = 0; i < toDrawTopLevel.size(); i++ )
            {
                toDrawTopLevel[i]->draw( *Win );
            }

            for( unsigned int i = 0; i < toDrawConsoleLevel.size(); i++ )
            {
                toDrawConsoleLevel[i]->draw( *Win );
            }

            Win->display();
            #if defined PF_OUTPUT_DEBUG_C_CONSOLE
                std::cout << "Time spent for drawing = " << DrawTime.asSeconds() << std::endl;
            #elif defined PF_OUTPUT_DEBUG_GAME_CONSOLE
                std::stringstream ss;
                ss << "Time spent for drawing = " << DrawTime.asSeconds();
                std::string log;
                ss >> log;
                console_data_grabber::getDataBank().addLog( log );
            #endif
        }
    };
private:

    void clearAll()
    {
        if( toDraw.size() )
        {
            for( unsigned int i = toDraw.size(); i > 0; i-- )
            {
                toDraw[i] = NULL;
                toDraw.erase( toDraw.begin() + i );
            }
        }
        if( toDrawTopLevel.size() )
        {
            for( unsigned int i = toDrawTopLevel.size(); i > 0; i-- )
            {
                toDrawTopLevel[i] = NULL;
                toDrawTopLevel.erase( toDrawTopLevel.begin() + i );
            }
        }
        if( toDrawConsoleLevel.size() )
        {
            for( unsigned int i = toDrawConsoleLevel.size(); i > 0; i-- )
            {
                toDrawConsoleLevel[i] = NULL;
                toDrawConsoleLevel.erase( toDrawConsoleLevel.begin() + i );
            }
        }
    };

    std::vector< extend::drawable * > toDraw;

    std::vector< extend::drawable * > toDrawTopLevel;

    std::vector< extend::drawable * > toDrawConsoleLevel;
};

#endif // drawer_hpp
