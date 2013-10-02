#ifndef resourcesConsole_hpp
#define resourcesConsole_hpp

#include <vector>
#include <string>

namespace resource
{
    class windowConsoleRes
    {
    private:
        windowConsoleRes() {};
        windowConsoleRes( const windowConsoleRes & conf ) {};
        windowConsoleRes * operator=( const windowConsoleRes & conf ) {};
        ~windowConsoleRes() {};
    public:
        static windowConsoleRes & getResPack() { static windowConsoleRes instance; return instance; };

        const bool load()
        {


            _initialized = true;
            return true;
        };

        sf::Texture & operator[]( const std::string & key ) { if( _initialized ) return _textures[ _fitKey( key ) ]; };

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

        bool _initialized = false;
    };
}

#endif // resourcesConsole_hpp
