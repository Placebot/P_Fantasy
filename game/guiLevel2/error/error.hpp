#ifndef error_hpp
#define error_hpp

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include <SFML/Graphics.hpp>

#include <gameGlobals/gameGlobals.hpp>
#if defined PF_OUTPUT_DEBUG_GAME_CONSOLE
    #include <gameGlobals/console/consoleDataGrabber.hpp>
#endif

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
                #if defined PF_OUTPUT_DEBUG_C_CONSOLE
                    std::cout << "Could not load /gui_level_2/error files" << std::endl;
                #elif defined PF_OUTPUT_DEBUG_GAME_CONSOLE
                    .consoleDataGrabber::getDataBank().addLog( "Could not load /guiLevel2/error files" );
                #endif

                return false;
            }

            for( unsigned int i = 0; i < 9; i++ )
                _sprites.push_back( sf::Sprite() );

            for( unsigned int i = 0; i < 0; i++ )
                _sprites[i].setTexture( _textures[i] );

            loaded = true;
            return true;
        };

        void display( const std::string text, const std::string titlePart = "none", const std::string   )
        {
            if( loaded )
            {
                while( gameState::config::getConfig().getRunning() )
                {

                }
            }
        };

    private:
        bool loaded = false;
        std::vector< sf::Texture > _textures;
        std::vector< sf::Sprite > _sprites;
    };
}

#endif // error_hpp
