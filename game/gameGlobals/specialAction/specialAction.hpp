#ifndef specialAction_hpp
#define specialAction_hpp

#include <gameGlobals/topLevelGlobals.hpp>

namespace specialAction
{
    class action
    {
    public:
        action( functionPointer action ) { _myAction = action; };
        action() {};
        ~action() { _myAction = NULL; };

        void setAction( functionPointer action ) { _myAction = action; };
        bool start() { if( _myAction != NULL ){ _myAction(); return true; }else return false; };
    private:
        functionPointer _myAction = NULL;
    };
}

#endif // specialAction_hpp
