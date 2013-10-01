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
            _keys_spr.push_back( "mainMenuBackground" );

            unsigned int charSize = 16;

            ///New Game
            options[0].setString( "New Game" );
            options[0].setCharacterSize( charSize );
            options[0].setPosition( 100.0, 530.0 );
            options[0].setColor( sf::Color::Black );
            options[0].setFont( fonts::getFonts().getFont("regular") );

            ///Load
            options[1].setString( "Load" );
            options[1].setCharacterSize( charSize );
            options[1].setPosition( 500.0, 530.0 );
            options[1].setColor( sf::Color::Black );
            options[1].setFont( fonts::getFonts().getFont("regular") );

            ///Options
            options[2].setString( "Options" );
            options[2].setCharacterSize( charSize );
            options[2].setPosition( 100.0, 550.0 );
            options[2].setColor( sf::Color::Black );
            options[2].setFont( fonts::getFonts().getFont("regular" ) );

            ///Multiplayer
            options[3].setString( "Multiplayer" );
            options[3].setCharacterSize( charSize );
            options[3].setPosition( 500.0, 550.0 );
            options[3].setColor( sf::Color::Black );
            options[3].setFont( fonts::getFonts().getFont("regular") );

            ///Exit
            options[4].setString( "Exit" );
            options[4].setCharacterSize( charSize );
            options[4].setPosition( 500.0, 570.0 );
            options[4].setColor( sf::Color::Black );
            options[4].setFont( fonts::getFonts().getFont("regular") );
        };
        ~resources() {};

        virtual void draw( sf::RenderWindow & Win )
        {
            ///Background images
            if( _sprites.size() )
            {
                for( unsigned int i = 0; i < _sprites.size(); i++ )
                    Win.draw( _sprites[i] );
            }

            for( unsigned int i = 0; i < 5; i++ )
                Win.draw( options[i] );
        };

        sf::Sprite & operator[]( const std::string & key ) { return _sprites[ _fitKey(key) ]; };
        sf::Text & getText( std::string key ) { return options[_fitKeyText(key)]; };

    private:

        unsigned int _fitKey( const std::string & key )
        {
            for( unsigned int i = 0; i < _keys_spr.size(); i++ )
            {
                if( key == _keys_spr[i] )
                    return i;
            }
        };

        unsigned int _fitKeyText( const std::string key )
        {
            for( unsigned int i = 0; i < 5; i++ )
            {
                if( key == keys[i] )
                    return i;
            }
        }

        std::vector< sf::Sprite > _sprites;
        std::vector< std::string > _keys_spr;

        sf::Text options[5];
        std::string keys[5] = { "newGame", "load", "options", "multiplayer", "exit" };
    };
}

void mainMenu();

#endif // main_menu_hpp
