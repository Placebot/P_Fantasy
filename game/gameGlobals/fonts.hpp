#ifndef fonts_hpp
#define fonts_hpp

#include <vector>
#include <string>

class fonts
{
private:
    ~fonts() {};
    fonts() {};
    fonts * operator=( const fonts & ) {};
    fonts(const fonts &) {};
public:
    static fonts & getFonts() { static fonts instance; return instance; };

    sf::Font & getFont( const std::string key )
    {
        return _fonts[ _fitKey( key ) ];
    };

    sf::Font & operator[]( const std::string key )
    {
        return _fonts[ _fitKey( key ) ];
    };

    bool addFont( const std::string key, const std::string path )
    {
        for( unsigned int i = 0; i < _fonts.size(); i++ )
        {
            if( key == _keys[i] )
                return false;
        }

        sf::Font newFont;
        if( !newFont.loadFromFile( path ) )
            return false;

        _keys.push_back( key );
        _fonts.push_back( newFont );
        return true;
    };

private:
    unsigned int _fitKey( const std::string & key )
    {
        for( unsigned int i = 0; i < _fonts.size(); i++ )
        {
            if( key == _keys[i] )
                return i;
        }
    };

    std::vector< sf::Font > _fonts;
    std::vector< std::string > _keys;
};

#endif // fonts_hpp
