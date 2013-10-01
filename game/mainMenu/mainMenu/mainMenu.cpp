#include <mainMenu/mainMenu/mainMenu.hpp>

/*

========================

-NEW GAME- -LOAD-

-OPTIONS- -MULTI-

          -EXIT-

========================

*/

void writeOut( const MAINMenuMain::possibleChoices & currPick )
{
    std::cout << "CurrPick = ";
    if( currPick == MAINMenuMain::possibleChoices::_new )
        std::cout << "New Game" << std::endl;
    if( currPick == MAINMenuMain::possibleChoices::_load )
        std::cout << "Load Game" << std::endl;
    if( currPick == MAINMenuMain::possibleChoices::_exit )
        std::cout << "Exit" << std::endl;
    if( currPick == MAINMenuMain::possibleChoices::_multiplayer )
        std::cout << "Multiplayer" << std::endl;
    if( currPick == MAINMenuMain::possibleChoices::_options )
        std::cout << "Options" << std::endl;
    if( currPick == MAINMenuMain::possibleChoices::_nothing )
        std::cout << "BLANK" << std::endl;
}


void mainMenu()
{
    std::cout << "entering" << std::endl;

    MAINMenuMain::resources Graphics;
    drawer::getDrawer().push_back( Graphics );

    sf::RenderWindow *Win = gameState::config::getConfig().getWindow();
    sf::Clock timer;
    sf::Clock timer2;
    timer2.restart();

    MAINMenuMain::possibleChoices currentChoice = MAINMenuMain::possibleChoices::_new;

    while( gameState::config::getConfig().getRunning() )
    {
        sf::Event Event;
        while( Win->pollEvent( Event ) )
        {
            if( Event.type == sf::Event::Closed )
                gameState::config::getConfig().goOff();

            if( Event.type == sf::Event::KeyPressed || Event.type == sf::Event::KeyReleased )
            {
                if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Left ) )
                {
                    if( currentChoice == MAINMenuMain::possibleChoices::_load )
                        currentChoice = MAINMenuMain::possibleChoices::_new;

                    if( currentChoice == MAINMenuMain::possibleChoices::_multiplayer )
                        currentChoice = MAINMenuMain::possibleChoices::_options;
                }

                if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Right ) )
                {
                    if( currentChoice == MAINMenuMain::possibleChoices::_new )
                        currentChoice = MAINMenuMain::possibleChoices::_load;

                    if( currentChoice == MAINMenuMain::possibleChoices::_options )
                        currentChoice = MAINMenuMain::possibleChoices::_multiplayer;
                }

                if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Up ) )
                {
                    if( currentChoice == MAINMenuMain::possibleChoices::_options )
                        currentChoice = MAINMenuMain::possibleChoices::_new;

                    if( currentChoice == MAINMenuMain::possibleChoices::_multiplayer )
                        currentChoice = MAINMenuMain::possibleChoices::_load;

                    if( currentChoice == MAINMenuMain::possibleChoices::_exit )
                        currentChoice = MAINMenuMain::possibleChoices::_multiplayer;
                }

                if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Down ) )
                {
                    switch( currentChoice )
                    {
                    case MAINMenuMain::possibleChoices::_new:
                        currentChoice = MAINMenuMain::possibleChoices::_options;
                        break;

                    case MAINMenuMain::possibleChoices::_load:
                        currentChoice = MAINMenuMain::possibleChoices::_multiplayer;
                        break;

                    case MAINMenuMain::possibleChoices::_multiplayer:
                        currentChoice = MAINMenuMain::possibleChoices::_exit;
                        break;
                    }
                }

                if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Return ) )
                {
                    ///
                }

            }

            if( Event.type == sf::Event::LostFocus )
                std::cout << "Focus lost!" << std::endl;

            if( Event.type == sf::Event::GainedFocus )
                std::cout << "Focus gained!" << std::endl;
        }

        if( timer.getElapsedTime().asSeconds() > 5 )
        {
            timer.restart();
            std::cout << "still alive~" << std::endl;
        }

        if( timer2.getElapsedTime().asSeconds() > 1 )
        {
            writeOut( currentChoice );
            timer2.restart();
        }



        drawer::getDrawer().draw();
    }
    std::cout << "exciting" << std::endl;

    drawer::getDrawer().remove( Graphics );
    std::cout << "here?" << std::endl;
}
