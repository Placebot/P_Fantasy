#include <gameGlobals/interpreter/interpreterStack.hpp>

namespace interpreter
{
    std::vector< std::string > split( std::string str, std::string deliminator) ///! Zeke's code
    {
        std::vector< std::string > tokens;
        size_t pos = 0;
        while( true )
        {
            size_t nextPos = str.find(deliminator,pos);
            if(nextPos == str.npos) { tokens.push_back( std::string( str.substr( pos, nextPos - pos ) ) ); break; };
            tokens.push_back( std::string( str.substr( pos, nextPos - pos ) ) );
            pos = nextPos + 1;
        }
        return tokens;
    }
}
