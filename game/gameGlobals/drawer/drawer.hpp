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
        {
            toDraw.push_back( &object );
            toDrawA.push_back( NULL );
        }
        else if( qType == topQueue )
        {
            toDrawTopLevel.push_back( &object );
            toDrawATopLevel.push_back( NULL );
        }
        else if( qType == console )
        {
            toDrawConsoleLevel.push_back( &object );
            toDrawAConsoleLevel.push_back( NULL );
        }
    };

    void push_back( animateable & object, const drawQueue qType )
    {
        if( qType == normal )
        {
            toDrawA.push_back( &object );
            toDraw.push_back( NULL );
        }
        else if( qType == topQueue )
        {
            toDrawATopLevel.push_back( &object );
            toDrawTopLevel.push_back( NULL );
        }
        else if( qType == console )
        {
            toDrawAConsoleLevel.push_back( &object );
            toDrawConsoleLevel.push_back( NULL );
        }
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
                        toDrawA[i] = NULL;
                        toDrawA.erase( toDrawA.begin() + i );
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
                        toDrawATopLevel[i] = NULL;
                        toDrawATopLevel.erase( toDrawATopLevel.begin() + i );
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
                        toDrawAConsoleLevel[i] = NULL;
                        toDrawAConsoleLevel.erase( toDrawAConsoleLevel.begin() + i );
                    }
                }
            }
        }
    };

    void remove( animateable & object, const drawQueue qType )
    {
        if( qType == normal )
        {
            if( toDrawA.size() )
            {
                for( unsigned int i = 0; i < toDrawA.size(); i++ )
                {
                    if( toDrawA[i] == &object )
                    {
                        toDraw[i] = NULL;
                        toDraw.erase( toDraw.begin() + i );
                        toDraw[i] = NULL;
                        toDrawA.erase( toDrawA.begin() + i );
                    }
                }
            }
        }
        else if( qType == topQueue )
        {
            if( toDrawATopLevel.size() )
            {
                for( unsigned int i = 0; i < toDrawATopLevel.size(); i++ )
                {
                    if( toDrawATopLevel[i] == &object )
                    {
                        toDrawTopLevel[i] = NULL;
                        toDrawTopLevel.erase( toDrawTopLevel.begin() + i );
                        toDrawTopLevel[i] = NULL;
                        toDrawATopLevel.erase( toDrawATopLevel.begin() + i );
                    }
                }
            }
        }
        else if( qType == console )
        {
            if( toDrawAConsoleLevel.size() )
            {
                for( unsigned int i = 0; i < toDrawAConsoleLevel.size(); i++ )
                {
                    if( toDrawAConsoleLevel[i] == &object )
                    {
                        toDrawConsoleLevel[i] = NULL;
                        toDrawConsoleLevel.erase( toDrawConsoleLevel.begin() + i );
                        toDrawConsoleLevel[i] = NULL;
                        toDrawAConsoleLevel.erase( toDrawAConsoleLevel.begin() + i );
                    }
                }
            }
        }
    };

    void draw()
    {
        if( toDraw.size() )
        {
            #if defined(PF_OUTPUT_DEBUG_C_CONSOLE) || defined(PF_OUTPUT_DEBUG_GAME_CONSOLE)
                sf::Clock DrawTime;
                DrawTime.restart();
            #endif
            sf::RenderWindow * Win = gameState::config::getConfig().getWindow();
            Win->clear();
            for( unsigned int i = 0; i < toDraw.size(); i++ )
            {
                if( toDraw[i] == NULL )
                {
                    toDrawA[i]->update();
                    toDrawA[i]->draw( *Win );
                }
                else
                    toDraw[i]->draw( *Win );
            }

            for( unsigned int i = 0; i < toDrawTopLevel.size(); i++ )
            {
                if( toDrawTopLevel[i] == NULL )
                {
                    toDrawATopLevel[i]->update();
                    toDrawATopLevel[i]->draw( *Win );
                }
                else
                    toDrawTopLevel[i]->draw( *Win );
            }

            for( unsigned int i = 0; i < toDrawConsoleLevel.size(); i++ )
            {
                if( toDrawConsoleLevel[i] == NULL )
                {
                    toDrawAConsoleLevel[i]->update();
                    toDrawAConsoleLevel[i]->draw( *Win );
                }
                else
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
                toDrawA[i] = NULL;
                toDraw.erase( toDraw.begin() + i );
                toDrawA.erase( toDrawA.begin() + i );
            }
        }
        if( toDrawTopLevel.size() )
        {
            for( unsigned int i = toDrawTopLevel.size(); i > 0; i-- )
            {
                toDrawTopLevel[i] = NULL;
                toDrawATopLevel[i] = NULL;
                toDrawTopLevel.erase( toDrawTopLevel.begin() + i );
                toDrawATopLevel.erase( toDrawATopLevel.begin() + i );
            }
        }
        if( toDrawConsoleLevel.size() )
        {
            for( unsigned int i = toDrawConsoleLevel.size(); i > 0; i-- )
            {
                toDrawConsoleLevel[i] = NULL;
                toDrawAConsoleLevel[i] = NULL;
                toDrawConsoleLevel.erase( toDrawConsoleLevel.begin() + i );
                toDrawAConsoleLevel.erase( toDrawAConsoleLevel.begin() + i );
            }
        }
    };

    std::vector< extend::drawable * > toDraw;
    std::vector< animateable * > toDrawA;

    std::vector< extend::drawable * > toDrawTopLevel;
    std::vector< animateable * > toDrawATopLevel;

    std::vector< extend::drawable * > toDrawConsoleLevel;
    std::vector< animateable * > toDrawAConsoleLevel;
};

#endif // drawer_hpp
