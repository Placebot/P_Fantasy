#ifndef resources_menus_hpp
#define resources_menus_hpp

#include <iostream>
#include <vector>
#include <string>

#include <game_globals/extend.hpp>

namespace resource
{
    class main_menu_res
    {
    private:
        main_menu_res() {};
        main_menu_res( const main_menu_res & conf ) {};
        main_menu_res * operator=( const main_menu_res & conf ) {};
        ~main_menu_res() {};
    public:
        static main_menu_res & getResPack() { static main_menu_res instance; return instance; };

        const bool load()
        {
            sf::Texture main_menu_background;
            if( !main_menu_background.loadFromFile( "resources/main_menu_bg.png" ) )
                return false;

            sf::Texture main_menu_settings_background;
            if( !main_menu_settings_background.loadFromFile( "resources/main_menu_st_bg.png" ) )
                return false;

            sf::Texture main_menu_load_backgrond;
            if( !main_menu_load_backgrond.loadFromFile( "resources/main_menu_ld_bg.png" ) )
                return false;

            sf::Texture main_menu_mp_background;
            if( !main_menu_mp_background.loadFromFile( "resources/main_menu_mp_bg.png" ) )
                return false;

            _textures.push_back( main_menu_background );
            _keys.push_back( "main_menu_background" );

            _textures.push_back( main_menu_settings_background );
            _keys.push_back( "main_menu_settings_background" );

            _textures.push_back( main_menu_load_backgrond );
            _keys.push_back( "main_menu_load_background" );

            _textures.push_back( main_menu_mp_background );
            _keys.push_back( "main_menu_mp_background" );

            initialized = true;
            return true;
        };

        sf::Texture & operator[]( const std::string & key ) { if( initialized = true ) return _textures[ _fitKey(key) ]; };

    private:

        unsigned int _fitKey( const std::string & key )
        {
            for( unsigned int i = 0; i < _textures.size(); i++ )
            {
                if( key == _keys[i] )
                    return i;
            }
        };

        std::vector< sf::Texture > _textures;
        std::vector< std::string > _keys;

        bool initialized = false;
    };
}

#endif // resources_menus_hpp
