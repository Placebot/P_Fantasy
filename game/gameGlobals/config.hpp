#ifndef config_hpp
#define config_hpp

#include <gameGlobals/extend.hpp>
#include <gameGlobals/topLevelGlobals.hpp>
#include <gameGlobals/keyBinding/keybind.hpp>


namespace gameState
{
    class config
    {
    private:
        config() {};
        config( const config & conf ) {};
        config * operator=( const config & conf ) {};
        ~config() {};
    public:
        static config & getConfig() { static config _object; return _object; };

        const volatile bool & getRunning() const { return _running; };
        sf::RenderWindow * getWindow() { return _gameWindow; };
        functionPointer getCurrFunc() { return _currentFunc; };
        void runFunc() { if( _currentFunc != NULL ) _currentFunc(); else std::cout << "Can't run. Function set to NULL" << std::endl; };

        void setGameWindow( sf::RenderWindow & Win ) { _gameWindow = &Win; };
        void goOff() { _running = false; if( _gameWindow != NULL ) { _gameWindow->close(); _gameWindow = NULL; exit(0); } };
        void setCurrFunc( functionPointer & newFunc ) { _currentFunc = newFunc; };
    private:
        volatile bool _running = true;
        sf::RenderWindow * _gameWindow = NULL;
        functionPointer _currentFunc = NULL;
    };

    class options
    {
    private:
        options() {};
        options( const options & conf ) {};
        options * operator=( const options & conf ) {};
        ~options() {};
    public:
        static options & getOptions() {};


        // Audio values
        const float getAudioVolume() const { return _masterAudioVolume; };

        const float getMusicVolumeValue() const { return _musicVolume * ( _masterAudioVolume / 100 ); };
        const float getMusicVolumeRatio() const { return getMusicVolumeValue() / 100; };

        const float getEffectsVolumeValue() const { return _effectsVolume * ( _masterAudioVolume / 100 ); };
        const float getEffectsVolumeRatio() const { return getEffectsVolumeValue() / 100; };

        void setAudioVolume( float audio ) { _masterAudioVolume = audio; };

        void setMusicVolume( float audio ) { _musicVolume = audio; };

        void setEffectsVolume( float audio ) { _musicVolume = audio; };

        const keybinds::keybind & getKeybind( const std::string & action ) { return _private::actionKeybinds::getKeybinds().getKey( action ); };

        const unsigned int getConsoleFontSize() { return _consoleFontSize; };

        void setConsoleFontSize( unsigned int size ) { _consoleFontSize = size; };

    private:
        float _masterAudioVolume = 100.0;
        float _musicVolume = 100.0;
        float _effectsVolume = 100.0;

        float _consoleFontSize = 16;
    };
}

#endif // config_hpp
