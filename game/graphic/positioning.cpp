#include <graphic/positioning.hpp>

namespace graphic
{
    sf::FloatRect getNewPosition( sf::FloatRect ToSet, sf::FloatRect MainArea, graphic::Position _pos )
    {
        sf::FloatRect toReturn;
        toReturn.height = ToSet.height;
        toReturn.width = ToSet.width;
        switch( _pos )
        {
        case Center: case Center_Bottom: case Center_Middle: case Center_Top:
            {
                toReturn.left = (MainArea.width/2 + MainArea.left) - (ToSet.width/2);

                switch( _pos )
                {
                case Center:
                    {
                        toReturn.top = ToSet.top;
                    }
                    break;

                case Center_Bottom:
                    {
                        toReturn.top = MainArea.top + (MainArea.height - ToSet.height);
                    }
                    break;

                case Center_Middle:
                    {
                        toReturn.top = MainArea.height /2 + MainArea.top - (ToSet.height/2);
                    }
                    break;

                case Center_Top:
                    {
                        toReturn.top = MainArea.top;
                    }
                    break;
                }
            }
            break;

        case Left: case Left_Bottom: case Left_Middle: case Left_Top:
            {
                toReturn.left = MainArea.left;

                switch( _pos )
                {
                case Left:
                    {
                        toReturn.top = ToSet.top;
                    }
                    break;

                case Left_Bottom:
                    {
                        toReturn.top = MainArea.top + (MainArea.height - ToSet.height);
                    }
                    break;

                case Left_Middle:
                    {
                        toReturn.top = MainArea.height /2 + MainArea.top - (ToSet.height/2);
                    }
                    break;

                case Left_Top:
                    {
                        toReturn.top = MainArea.top;
                    }
                    break;
                }
            }
            break;

        case Right: case Right_Bottom: case Right_Middle: case Right_Top:
            {
                toReturn.left = MainArea.width - ToSet.width + MainArea.left;

                switch( _pos )
                {
                case Right:
                    {
                        toReturn.top = ToSet.top;
                    }
                    break;

                case Right_Bottom:
                    {
                        toReturn.top = MainArea.top + (MainArea.height - ToSet.height);
                    }
                    break;

                case Right_Middle:
                    {
                        toReturn.top = MainArea.height /2 + MainArea.top - (ToSet.height/2);
                    }
                    break;

                case Right_Top:
                    {
                        toReturn.top = MainArea.top;
                    }
                    break;
                }
            }
            break;
        }

        return toReturn;
    }
}
