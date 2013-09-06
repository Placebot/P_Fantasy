#include <gameGlobals/keyBinding/keybind.hpp>

namespace keybinds
{
    const bool checkAction( const keybinds::keybind & k, const sf::Event & e )
    {
        // Mouse event
        if (k.myInputType == MouseInput &&
            k.myEventType == e.type &&
            k.myMouseButton == e.mouseButton.button)
        {
            return true;
        }
        // Keyboard event
        if (k.myInputType == KeyboardInput &&
            k.myEventType == e.type &&
            k.myKeyCode == e.key.code)
        {
            return true;
        }
        return false;
    }
}
