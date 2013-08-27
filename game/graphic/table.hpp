#ifndef table_hpp
#define table_hpp

#include <SFML/Graphics.hpp>

namespace graphic
{
    class table
    {
    public:
        table( const sf::FloatRect & base, unsigned int rows, unsigned int columns ) { countOut( base, rows, columns ); };
        table() {};
        ~table() {};

        void countOut( const sf::FloatRect & base, unsigned int rows, unsigned int columns ) { _w = base.width / columns; _h = base.height / rows; };
        const float getWidth() const { return _w; };
        const float getHeight() const { return _h; };
    private:
        float _w = 0.0;
        float _h = 0.0;
    };
}
#endif // table_hpp
