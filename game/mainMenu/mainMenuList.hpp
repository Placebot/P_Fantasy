#ifndef mainMenuList_hpp
#define mainMenuList_hpp

#include <iostream>
#include <gameGlobals/config.hpp>
#include <gameGlobals/topLevelGlobals.hpp>

#include <mainMenu/mainMenuMpStart/mainMenuMpStart.hpp>
#include <mainMenu/mainMenuSettings/mainMenuSettings.hpp>
#include <mainMenu/mainMenuLoad/mainMenuLoad.hpp>
#include <mainMenu/mainMenu/mainMenu.hpp>

namespace menu
{
    enum menuFunc
    {
        main,
        main_menu_ld,
        main_menu_st,
        //------ Single Player
        main_menu_mp
    };

    class menuState
    {
    private:
        menuState() { _point = mainMenu; };
        menuState( const menuState & conf ) {};
        menuState * operator=( const menuState & conf ) {};
        ~menuState() {};
    public:
        static menuState & getMenu() { static menuState _object; return _object; };

        const menuFunc getMenuFunc() const { return _state; };
        void changeFunc( const menuFunc newFunc )
        {
            switch( newFunc )
            {
                case menuFunc::main:
                    { _point = mainMenu; }
                    break;

                case menuFunc::main_menu_ld:
                    { _point = mainMenuLoad; }
                    break;

                case menuFunc::main_menu_mp:
                    { _point = mainMenuMpStart; }
                    break;

                case menuFunc::main_menu_st:
                    { _point = mainMenuSettings; }
                    break;
            }
        };
        functionPointer & getFunc() { return _point; };

    private:
        menuFunc _state = main;
        functionPointer _point = NULL;
    };
}

#endif // main_menu_hpp
