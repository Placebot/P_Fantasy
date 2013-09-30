#ifndef extend_hpp
#define extend_hpp

#include <SFML/Graphics.hpp>
#include <gameGlobals/topLevelGlobals.hpp>

namespace extend
{
    class drawable
    {
    public:
        virtual void draw( sf::RenderWindow & Win ) = 0;
    };

    class pointable
    {
    public:
        virtual functionPointer getAction() = 0;
        virtual void setAction( functionPointer pointTo ) = 0;
        virtual const bool callAction() = 0;
    };
}

#endif // complexDrawable_hpp

