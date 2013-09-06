#ifndef animation_hpp
#define animation_hpp

#include <gameGlobals/extend.hpp>
#include <gameGlobals/updateable.hpp>

class animateable : public extend::drawable, public updateable
{
};

#endif // animation_hpp
