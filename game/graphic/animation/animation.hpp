#ifndef animation_hpp
#define animation_hpp

#include <gameGlobals/extend.hpp>
#include <gameGlobals/updateable.hpp>
#include <gameGlobals/status.hpp>
#include <graphic/animation/animationClock.hpp>
#include <graphic/animation/frame.hpp>

class animateable : public extend::drawable, public updateable
{
public:
    virtual void startAnimation() = 0;
    virtual void stopAnimation() = 0;
    virtual void pauseAnimation() = 0;
    virtual status getStatus() = 0;
};

#endif // animation_hpp
