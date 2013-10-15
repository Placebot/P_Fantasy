#ifndef table_hpp
#define table_hpp

#include <SFML/Graphics.hpp>
#include <vector>

namespace graphic
{
    class table
    {
    public:
        table( sf::FloatRect base, unsigned int rows, unsigned int colls )
        {
            myBase = base;
            myRows = rows;
            myCols = colls;
            resize();
            populate();
        };

        ~table();

        sf::FloatRect getCell( unsigned int row, unsigned int col ){ return me[row][col]; };

    private:
        void resize() { me.resize( myRows ); for( unsigned int i = 0; i < myCols; i++ ) me[i].resize( myCols ); };
        void populate()
        {
            float nextLeft = myBase.left;
            float nextTop = myBase.top;
            for( unsigned int row = 0; row < myRows; row++ )
            {
                for( unsigned int col = 0; col < myCols; col++ )
                {
                    sf::FloatRect temp;
                    temp.left = nextLeft;
                    temp.top = nextTop;
                    temp.height = myBase.height / myRows;
                    temp.width = myBase.width / myCols;
                    me[row][col] = temp;
                    nextLeft = myBase.width / myCols + nextLeft;
                }
                nextTop = nextTop + myBase.height / myRows;
                nextLeft = myBase.left;
            }
        };
        unsigned int myRows;
        unsigned int myCols;
        sf::FloatRect myBase;

        std::vector< std::vector< sf::FloatRect > > me;
    };
}
#endif // table_hpp
