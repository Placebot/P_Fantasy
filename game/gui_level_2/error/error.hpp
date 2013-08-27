#ifndef error_hpp
#define error_hpp

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>

namespace gui
{
    class error
    {
    private:
        ~error() {};
        error() {};
        error * operator=( const error & ) {};
        error(const error &) {};
    public:
        static error & getClass() { static error _this; return _this; };

        bool initialize( std::string _basePath )
        {
            for( unsigned int i = 0; i < 9; i++ )
                _textures.push_back( sf::Texture() );

            try
            {
                for( unsigned int i = 0; i < 9; i++ )
                {
                    std::stringstream ss;
                    ss << i;
                    std::string numb;
                    ss >> numb;
                    std::string _currPath = _basePath + numb + ".png";
                    if(!_textures[i].loadFromFile( _currPath ) )
                    {
                        bool err = true;
                        throw err;
                    }
                }
            }
            catch( bool _error )
            {
                std::cout << "Could not load /gui_level_2/error files" << std::endl;
                return false;
            }

            for( unsigned int i = 0; i < 9; i++ )
                _sprites.push_back( sf::Sprite() );

            for( unsigned int i = 0; i < 0; i++ )
                _sprites[i].setTexture( _textures[i] );

            return true;
        };

        void display( const std::string text, const std::string titlePart = "none" )
        {

        };

    private:
        std::vector< sf::Texture > _textures;
        std::vector< sf::Sprite > _sprites;
    };
}

#endif // error_hpp
