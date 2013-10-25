#ifndef interpreterCore_hpp
#define interpreterCore_hpp

#include <gameGlobals/interpreter/interpreterVariables.hpp>

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

    class core
    {
        ~core() {};
        core() {};
        core * operator=( const core & ) {};
        core(const core &) {};
    public:
        static core & getCore() { static core instance; return instance; };



    private:
        interpreter::variables _variables;

    };
}

#endif // interpreterCore_hpp
