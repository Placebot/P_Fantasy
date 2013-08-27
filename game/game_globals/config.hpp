#ifndef config_hpp
#define config_hpp

#include <game_globals/extend.hpp>
#include <game_globals/top_level_globals.hpp>

namespace game_state
{
    enum state
    {
        main_menu,
        //------ Main Menu
        new_game,
        game,
        //------ Single Player
        game_mp,
        //------ Game
        in_game_menu,
        in_game_menu_squad,
        in_game_menu_load,
        in_game_menu_save,
        in_game_menu_settings,
        //------ Single Player
        in_game_menu_mp
        //------ In-game menu
    };

    enum location
    {
        test1
    };

    class config
    {
    private:
        config() {};
        config( const config & conf ) {};
        config * operator=( const config & conf ) {};
        ~config() {};
    public:
        static config & getConfig() { static config _object; return _object; };

        const state & getState() { return _gameState; };
        const location & getLocation() { return _playerLocation; };
        const volatile bool & getRunning() const { return _running; };
        sf::RenderWindow * getWindow() { return _gameWindow; };
        functionPointer getCurrFunc() { return _currentFunc; };
        void runFunc() { _currentFunc(); };

        void changeState( const state newState ) { _gameState = newState; };
        void changeLocation( const location newLocation ) { _playerLocation = newLocation; };
        void setGameWindow( sf::RenderWindow & Win ) { _gameWindow = &Win; };
        void goOff() { _running = false; if( _gameWindow != NULL ) { _gameWindow->close(); _gameWindow = NULL; } };
        void setCurrFunc( functionPointer & newFunc ) { _currentFunc = newFunc; };
    private:
        state _gameState = main_menu;
        location _playerLocation = test1;
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


    };
}

#endif // config_hpp
