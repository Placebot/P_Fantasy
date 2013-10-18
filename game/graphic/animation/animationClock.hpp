#ifndef animationClock_hpp
#define animationClock_hpp

#include <SFML/System/Clock.hpp>
#include <gameGlobals/status.hpp>

class animationClock
{
public:
    animationClock() {};
    ~animationClock() { if( timer != NULL ) delete timer; if( lastTime != NULL ) delete lastTime;  };

    void restart() { if( timer == NULL ) timer = new sf::Clock; timer->restart(); if( lastTime != NULL ){ delete lastTime; lastTime = NULL; } };
    void start() { if( timer == NULL ) timer = new sf::Clock; timer->restart(); };
    void pause() { if( timer != NULL ){ if( lastTime == NULL ) lastTime = new sf::Time; *lastTime = timer->getElapsedTime(); } };
    void stop() { if( timer != NULL ){ delete timer; timer = NULL; } if( lastTime != NULL ){ delete lastTime; lastTime = NULL; } };

    const sf::Time getElapsedTime() const { sf::Time toReturn; if( timer != NULL ) toReturn += timer->getElapsedTime(); if( lastTime != NULL ) toReturn += *lastTime; return toReturn; };

    const status getState() const { return state; };
private:
    sf::Clock * timer = NULL;
    sf::Time * lastTime = NULL;
    status state = stopped;
};
#endif // animationClock_hpp
