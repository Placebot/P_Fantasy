#ifndef animation_hpp
#define animation_hpp

#include <game_globals/extend.hpp>
#include <game_globals/updateable.hpp>

class animateable : public extend::drawable, public updateable
{
};

#endif // animation_hpp
