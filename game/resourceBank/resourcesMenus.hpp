#ifndef resourcesMenus_hpp
#define resourcesMenus_hpp

#include <iostream>
#include <vector>
#include <string>

#include <gameGlobals/extend.hpp>

namespace resource
{
    class mainMenuRes
    {
    private:
        mainMenuRes() {};
        mainMenuRes( const mainMenuRes & conf ) {};
        mainMenuRes * operator=( const mainMenuRes & conf ) {};
        ~mainMenuRes() {};
    public:
        static mainMenuRes & getResPack() { static mainMenuRes instance; return instance; };

        const bool load()
        {
            sf::Texture mainMenuBackground;
            if( !mainMenuBackground.loadFromFile( "resources/backgrounds/mainMenuBg.png" ) )
                return false;

            sf::Texture mainMenuSettingsBackground;
            if( !mainMenuSettingsBackground.loadFromFile( "resources/backgrounds/mainMenuStBg.png" ) )
                return false;

            sf::Texture mainMenuLoadBackgrond;
            if( !mainMenuLoadBackgrond.loadFromFile( "resources/backgrounds/mainMenuLdBg.png" ) )
                return false;

            sf::Texture mainMenuMpBackground;
            if( !mainMenuMpBackground.loadFromFile( "resources/backgrounds/mainMenuMpBg.png" ) )
                return false;

            _textures.push_back( mainMenuBackground );
            _keys.push_back( "mainMenuBackground" );


            _textures.push_back( mainMenuSettingsBackground );
            _keys.push_back( "mainMenuSettingsBackground" );
            _putBool();

            _textures.push_back( mainMenuLoadBackgrond );
            _keys.push_back( "mainMenuLoadMackground" );
            _putBool();

            _textures.push_back( mainMenuMpBackground );
            _keys.push_back( "mainMenuMpBackground" );
            _putBool();

            initialized = true;
            return true;
        };

        sf::Texture & operator[]( const std::string & key ) { if( initialized == true ) return _textures[ _fitKey(key) ]; };
        const bool getLocked( const std::string & key ) { if( initialized == true ) { return _locked[ _fitKey( key ) ]; } else return false; };

    private:

        void _putBool()
        {
            bool poot = false;
            _locked.push_back( poot );
        }

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
        std::vector< bool > _locked;

        bool initialized = false;
    };
}

#endif // resources_menus_hpp
