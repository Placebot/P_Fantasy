#include <gameGlobals/console/console.hpp>

namespace console
{
    void consoleActivation( sf::Event & event )
    {
        if( event.type == sf::Event::KeyPressed
           && sf::Keyboard::isKeyPressed( sf::Keyboard::Tilde ) )
           console::windowConsole::getWinConsole().boot();
    }
}
