#ifndef main_menu_hpp
#define main_menu_hpp

#include <iostream>
#include <game_globals/game_globals.hpp>

#include <resource_bank/resources_menus.hpp>

namespace MAIN_menu_main
{
    class resources : public extend::drawable
    {
    public:
        resources()
        {
            sf::Sprite main_menu_background;
            main_menu_background.setTexture( resource::main_menu_res::getResPack()[ "main_menu_background" ] );

            _sprites.push_back( main_menu_background );
            _keys.push_back( "main_menu_background" );
        };
        ~resources() {};

        virtual void draw( sf::RenderWindow & Win )
        {
            if( _sprites.size() )
            {
                for( unsigned int i = 0; i < _sprites.size(); i++ )
                    Win.draw( _sprites[i] );
            }
        };

        sf::Sprite & operator[]( const std::string & key ) { return _sprites[ _fitKey(key) ]; };

    private:

        unsigned int _fitKey( const std::string & key )
        {
            for( unsigned int i = 0; i < _keys.size(); i++ )
            {
                if( key == _keys[i] )
                    return i;
            }
        };

        std::vector< sf::Sprite > _sprites;
        std::vector< std::string > _keys;
    };
}

void main_menu();

#endif // main_menu_hpp
