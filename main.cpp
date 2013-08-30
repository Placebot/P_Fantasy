#include <iostream>

#include <SFML/Graphics.hpp>
#include <game_globals/game_globals.hpp>
#include <game_globals/music.hpp>

#include <main_menu/main_menu_list.hpp>

#include <resource_bank/resources_menus.hpp>

int main()
{
    sf::RenderWindow GameWin;
    GameWin.create(sf::VideoMode(800, 600, 32), "Pony Fantasy Alpha" );

    game_state::config::getConfig().setGameWindow( GameWin );
    game_state::config::getConfig().setCurrFunc( menu::menuState::getMenu().getFunc() );

    if( !resource::main_menu_res::getResPack().load() )
        return -1;

    while( game_state::config::getConfig().getRunning() )
    {
        game_state::config::getConfig().runFunc();
    }
    return 0;
}
