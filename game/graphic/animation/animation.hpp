#ifndef animation_hpp
#define animation_hpp

#include <game_globals/extend.hpp>

class animateable : public extend::drawable
{
public:
    virtual void update() = 0;
};

#endif // animation_hpp
