#include <iostream>

#include <SFML/Graphics.hpp>
#include <game_globals/game_globals.hpp>
#include <graphic/graphic.hpp>
#include <file_utilities/serializeable.hpp>

#include <game_globals/music/musicPlayer.hpp>
#include <game_globals/music/playlist.hpp>

#include <main_menu/main_menu_list.hpp>

#include <game_globals/key_binding/keybind.hpp>

int main()
{
    sf::RenderWindow GameWin;
    GameWin.create(sf::VideoMode(800, 600, 32), "Pony Fantasy Alpha" );

    game_state::config::getConfig().setGameWindow( GameWin );
    game_state::config::getConfig().setCurrFunc( menu::menuState::getMenu().getFunc() );

    GameWin.display();
    while( game_state::config::getConfig().getRunning() )
    {
        game_state::config::getConfig().runFunc();
    }
    return 0;
}
