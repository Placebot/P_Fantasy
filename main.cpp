#include <iostream>

#include <SFML/Graphics.hpp>
#include <gameGlobals/gameGlobals.hpp>
#include <gameGlobals/music.hpp>

#include <graphic/graphic.hpp>

#include <gameGlobals/achievementSystem/achievementSystemMain.hpp>

int main()
{
    sf::RenderWindow GameWin;
    GameWin.create(sf::VideoMode(800, 600, 32), "P_F" );

    gameState::config::getConfig().setGameWindow( GameWin );

    if( !fonts::getFonts().addFont("regular", "resources/fonts/LiberationSans-Regular.ttf" )
       //|| !fonts::getFonts().addFont("boldItalic", "resources/fonts/LiberationSans-BoldItalic.tff")
       || !fonts::getFonts().addFont("italic", "resources/fonts/LiberationSans-Italic.ttf")
       //|| !fonts::getFonts().addFont("bold", "resources/fonts/LiberationSans-Bold.tff" )
       )
        return -1;


    while( gameState::config::getConfig().getRunning() )
    {
        gameState::config::getConfig().runFunc();
    }
    return 0;
}
