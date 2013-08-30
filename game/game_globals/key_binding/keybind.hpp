#ifndef keybind_hpp
#define keybind_hpp

#include <iostream>
#include <string>

namespace keybinds
{
    enum InputType
    {
        KeyboardInput,
        MouseInput,
        JoystickInput
    };

    struct keybind
    {
        InputType myInputType;
        sf::Event::EventType myEventType;
        sf::Keyboard::Key myKeyCode;
        sf::Mouse::Button myMouseButton;
    };
}

namespace _private
{
    class action_keybinds
    {
        action_keybinds() {};
        action_keybinds( const action_keybinds & conf ) {};
        action_keybinds * operator=( const action_keybinds & conf ) {};
        ~action_keybinds() {};

        unsigned int _fitKey( const std::string & action )
        {
            for( unsigned int i = 0; i < mapped.size(); i++ )
            {
                if( action == mapped[i] )
                    return i;
            }
        };

        const keybinds::keybind & getKey( const std::string & action ) { return keys[ _fitKey(action) ]; };

        std::vector< keybinds::keybind > keys;
        std::vector< std::string > mapped;
    };
}

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

#endif // keybind_hpp
