#ifndef keybind_hpp
#define keybind_hpp

#include <iostream>
#include <string>
#include <SFML/Window.hpp>
#include <fileUtilities/serializeable.hpp>

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

namespace gameState
{
    class options;
}

namespace _private
{
    class actionKeybinds : public file::serializeable
    {
        friend class gameState::options;
        actionKeybinds() {};
        actionKeybinds( const actionKeybinds & conf ) {};
        actionKeybinds * operator=( const actionKeybinds & conf ) {};
        ~actionKeybinds() {};

        static actionKeybinds & getKeybinds() { static actionKeybinds instance; return instance; };

        unsigned int _fitKey( const std::string & action )
        {
            for( unsigned int i = 0; i < mapped.size(); i++ )
            {
                if( action == mapped[i] )
                    return i;
            }
        };

        const keybinds::keybind & getKey( const std::string & action ) { return keys[ _fitKey(action) ]; };

        virtual const bool save( const std::string path, unsigned int mode = 0 ) {};
        virtual const bool load( const std::string path, bool directFromString = false ) {};

        keybinds::keybind & operator[]( const std::string & action ) { return keys[ _fitKey( action) ]; };

        std::vector< keybinds::keybind > keys;
        std::vector< std::string > mapped;
    };
}

namespace keybinds
{
    const bool checkAction( const keybinds::keybind & k, const sf::Event & e );
}

#endif // keybind_hpp
