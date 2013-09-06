#ifndef extend_hpp
#define extend_hpp

#include <SFML/Graphics.hpp>

namespace extend
{
    class drawable
    {
    public:
        virtual void draw( sf::RenderWindow & Win ) = 0;
    };
}

#endif // complexDrawable_hpp

