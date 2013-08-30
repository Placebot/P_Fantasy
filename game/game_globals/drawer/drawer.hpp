#ifndef drawer_hpp
#define drawer_hpp

#include <iostream>
#include <vector>
#include <game_globals/extend.hpp>
#include <game_globals/config.hpp>
#include <graphic/animation/animation.hpp>
#include <game_globals/console/console_data_grabber.hpp>

#if defined PF_OUTPUT_DEBUG_GAME_CONSOLE
    #include <sstream>
#endif

namespace game_state
{
    class config;
}

class drawer
{
private:
    friend class game_state::config;
    ~drawer() {};
    drawer() {};
    drawer * operator=( const drawer & ) {};
    drawer(const drawer &) {};
public:
    static drawer & getDrawer() { static drawer _instance; return _instance; };

    void push_back( extend::drawable & object ) { toDraw.push_back( &object ); toDrawA.push_back( NULL ); };
    void push_back( animateable & object ) { toDrawA.push_back( &object ); toDraw.push_back( NULL ); };
    void remove( extend::drawable & object ) { if( toDraw.size() ){ for( unsigned int i = 0; i < toDraw.size(); i++ ){ if( toDraw[i] == &object ) { toDraw[i] = NULL; toDraw.erase( toDraw.begin() + i ); toDrawA[i] = NULL; toDrawA.erase( toDrawA.begin() + i ); } } } };
    void remove( animateable & object ) { if( toDrawA.size() ){ for( unsigned int i = 0; i < toDrawA.size(); i++ ){ if( toDrawA[i] == &object ) { toDraw[i] = NULL; toDraw.erase( toDraw.begin() + i ); toDraw[i] = NULL; toDrawA.erase( toDrawA.begin() + i ); } } } };

    void push_back_top_queue( extend::drawable & object ) { toDrawTopLevel.push_back( &object ); toDrawATopLevel.push_back( NULL ); };
    void push_back_top_queue( animateable & object ) { toDrawATopLevel.push_back( &object ); toDrawTopLevel.push_back( NULL ); };
    void remove_top_queue( extend::drawable & object ) { if( toDrawTopLevel.size() ){ for( unsigned int i = 0; i < toDrawTopLevel.size(); i++ ){ if( toDrawTopLevel[i] == &object ) { toDrawTopLevel[i] = NULL; toDrawTopLevel.erase( toDrawTopLevel.begin() + i ); toDrawATopLevel[i] = NULL; toDrawATopLevel.erase( toDrawATopLevel.begin() + i ); } } } };
    void remove_top_queue( animateable & object ) { if( toDrawATopLevel.size() ){ for( unsigned int i = 0; i < toDrawATopLevel.size(); i++ ){ if( toDrawATopLevel[i] == &object ) { toDrawTopLevel[i] = NULL; toDrawTopLevel.erase( toDrawTopLevel.begin() + i ); toDrawATopLevel[i] = NULL; toDrawATopLevel.erase( toDrawATopLevel.begin() + i ); } } } };

    void draw()
    {
        if( toDraw.size() )
        {
            #if defined(PF_OUTPUT_DEBUG_C_CONSOLE) || defined(PF_OUTPUT_DEBUG_GAME_CONSOLE)
                sf::Clock DrawTime;
                DrawTime.restart();
            #endif
            sf::RenderWindow * Win = game_state::config::getConfig().getWindow();
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
    };

    std::vector< extend::drawable * > toDraw;
    std::vector< animateable * > toDrawA;

    std::vector< extend::drawable * > toDrawTopLevel;
    std::vector< animateable * > toDrawATopLevel;
};

#endif // drawer_hpp
