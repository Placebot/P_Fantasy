#ifndef mainMenu_hpp
#define mainMenu_hpp

#include <iostream>
#include <gameGlobals/gameGlobals.hpp>

#include <resourceBank/resourcesMenus.hpp>

namespace MAINMenuMain
{
    enum possibleChoices
    {
        _nothing,
        _exit,
        _load,
        _multiplayer,
        _new,
        _options
    };

    class resources : public extend::drawable
    {
    public:
        resources()
        {
            sf::Sprite mainMenuBackground;
            mainMenuBackground.setTexture( resource::mainMenuRes::getResPack()[ "mainMenuBackground" ] );

            _sprites.push_back( mainMenuBackground );
            _keys.push_back( "mainMenuBackground" );
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

void mainMenu();

#endif // main_menu_hpp
