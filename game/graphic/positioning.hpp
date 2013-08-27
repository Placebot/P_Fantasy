#ifndef positioning_hpp
#define positioning_hpp

#include <SFML/Graphics.hpp>
#include <iostream>

namespace graphic
{
    enum Position
    {
        Left,
        Left_Top,
        Left_Middle,
        Left_Bottom,
        Center,
        Center_Middle,
        Center_Bottom,
        Center_Top,
        Right,
        Right_Middle,
        Right_Bottom,
        Right_Top
    };

    sf::FloatRect getNewPosition( sf::FloatRect ToSet, sf::FloatRect MainArea, Position _pos );
}
#endif // Rarity_Positioning_hpp
