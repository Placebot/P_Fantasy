#ifndef main_menu_list_hpp
#define main_menu_list_hpp

#include <iostream>
#include <game_globals/config.hpp>
#include <game_globals/top_level_globals.hpp>

#include <main_menu/main_menu_mp_start/main_menu_mp_start.hpp>
#include <main_menu/main_menu_settings/main_menu_settings.hpp>
#include <main_menu/main_menu_load/main_menu_load.hpp>
#include <main_menu/main_menu/main_menu.hpp>

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
        menuState() { _point = main_menu; };
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
                    { _point = main_menu; }
                    break;

                case menuFunc::main_menu_ld:
                    { _point = main_menu_load; }
                    break;

                case menuFunc::main_menu_mp:
                    { _point = main_menu_mp_start; }
                    break;

                case menuFunc::main_menu_st:
                    { _point = main_menu_settings; }
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
