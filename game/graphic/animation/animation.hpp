#ifndef animation_hpp
#define animation_hpp

#include <gameGlobals/extend.hpp>
#include <gameGlobals/updateable.hpp>

class animateable : public extend::drawable, public updateable
{
public:
    virtual void startAnimation() = 0;
    virtual void stopAnimation() = 0;
    virtual void updateAnimation() = 0;
};

#endif // animation_hpp
