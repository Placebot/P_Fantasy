#ifndef interpreterVariables_hpp
#define interpreterVariables_hpp

#include <vector>
#include <string>

#include <gameGlobals/fonts.hpp>
#include <gameGlobals/drawer/drawer.hpp>
#include <graphic/graphic.hpp>

#include <gameGlobals/music.hpp>

namespace interpreter
{
    class core;
    class variables;
    enum TOKENS
    {
        _MINUS = '-',
        _PLUS = '+',
        _MULTIPLY = '*',
        _DIVIDE = '/',
        _IF,
        _IF_ELSE,
        _ELSE,
        _ENDIF,
        _SCOPE_OPEN,
        _SCOPE_END,
        _NUMBER,
        _DOT = '.',
        _CREATE,
        _FUNCTION,
        _UNIQUE_ID
    };

    enum TYPE
    {
        _INT,
        _STRING,
        _FLOAT,
        _CHAR,
        /// Regular types
        _MUSIC,
        _SOUND,
        _PLAYLIST,
        /// Sound types
        _ANIMATION,
        _SPRITE,
        _STYLE,
        _TEXT,
        _SHADER
    };

    namespace _private
    {
        class dataChunk
        {
            friend class interpreter::core;
            friend class interpreter::variables;
            dataChunk( TYPE type, const std::string params )
            {
                myType = type;
                switch( type )
                {
                case _INT: { data = new int(); } break;
                case _STRING: { data = new std::string(); } break;
                case _CHAR: { data = new char(); } break;
                }
            };

            void * data = NULL;
            TYPE myType;
        };
    }


    class variables
    {
        friend class core;
        variables() {};
        ~variables() {};

        void* getData( const std::string key ) {}


    };
}
#endif // interpreterVariables_hpp
