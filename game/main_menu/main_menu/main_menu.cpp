#include <main_menu/main_menu/main_menu.hpp>

void main_menu()
{
    std::cout << "entering" << std::endl;

    MAIN_menu_main::resources Graphics;
    drawer::getDrawer().push_back( Graphics );

    sf::RenderWindow *Win = game_state::config::getConfig().getWindow();
    sf::Clock timer;
    while( game_state::config::getConfig().getRunning() )
    {
        sf::Event Event;
        while( Win->pollEvent( Event ) )
        {
            if( Event.type == sf::Event::Closed )
                game_state::config::getConfig().goOff();
        }

        if( timer.getElapsedTime().asSeconds() > 5 )
        {
            timer.restart();
            std::cout << "still alive~" << std::endl;
        }





        drawer::getDrawer().draw();
    }
    std::cout << "exciting" << std::endl;

    drawer::getDrawer().remove( Graphics );
    std::cout << "here?" << std::endl;
}
