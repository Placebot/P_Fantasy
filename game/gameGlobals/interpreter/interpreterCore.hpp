#ifndef interpreterCore_hpp
#define interpreterCore_hpp

#include <gameGlobals/interpreter/interpreterVariables.hpp>
#include <gameGlobals/interpreter/interpreterStack.hpp>

#include <gameGlobals/updateable.hpp>
#include <gameGlobals/updater.hpp>

namespace interpreter
{
    enum types
    {
        STRING,
        INT,
        FLOAT,
        CHAR,
        TEXT,
        ACHIEVEMENT,
        MUSIC,
        ANIMATION,
        DRAWABLE,
        FONT,
        STYLE
    };

    class core : public updateable
    {
        ~core() {};
        core() { updater::getUpdater().push_back( * this ); };
        core * operator=( const core & ) {};
        core(const core &) {};
    public:
        static core & getCore() { static core instance; return instance; };

        virtual void update()
        {

        };

    private:
        interpreter::variables _variables;
    };
}

#endif // interpreterCore_hpp
