#include <iostream>

#include <SFML/Graphics.hpp>
#include <gameGlobals/gameGlobals.hpp>
#include <gameGlobals/music.hpp>

#include <mainMenu/mainMenuList.hpp>

#include <resourceBank/resourcesMenus.hpp>

#include <graphic/guiLevel1/button.hpp>

int main()
{
    sf::RenderWindow GameWin;
    GameWin.create(sf::VideoMode(800, 600, 32), "P_F" );

    gameState::config::getConfig().setGameWindow( GameWin );
    gameState::config::getConfig().setCurrFunc( menu::menuState::getMenu().getFunc() );

    if( !resource::mainMenuRes::getResPack().load() )
        return -1;

    while( gameState::config::getConfig().getRunning() )
    {
        gameState::config::getConfig().runFunc();
    }
    return 0;
}
