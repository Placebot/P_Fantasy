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

class drawer
{
private:
    ~drawer() {};
    drawer() {};
    drawer * operator=( const drawer & ) {};
    drawer(const drawer &) {};
public:
    static drawer & getDrawer() { static drawer _instance; return _instance; };

    void addToQueue( extend::drawable & object ) { toDraw.push_back( &object ); toDrawA.push_back( NULL ); };
    void addToQueue( animateable & object ) { toDrawA.push_back( &object ); toDraw.push_back( NULL ); };
    void removeFromQueue( extend::drawable & object ) { if( toDraw.size() ){ for( unsigned int i = 0; i < toDraw.size(); i++ ){ if( toDraw[i] == &object ) { toDraw.erase( toDraw.begin() + i ); toDrawA.erase( toDrawA.begin() + i ); } } } };
    void removeFromQueue( animateable & object ) { if( toDrawA.size() ){ for( unsigned int i = 0; i < toDrawA.size(); i++ ){ if( toDrawA[i] == &object ) { toDraw.erase( toDraw.begin() + i ); toDrawA.erase( toDrawA.begin() + i ); } } } };

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
    std::vector< extend::drawable * > toDraw;
    std::vector< animateable * > toDrawA;
};

#endif // drawer_hpp