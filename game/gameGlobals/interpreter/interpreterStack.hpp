#ifndef interpreterStack_hpp
#define interpreterStack_hpp

#include <vector>
#include <string>

namespace interpreter
{
    class commandList;
    std::vector< std::string > split( std::string str, std::string deliminator); ///! Zeke's code

    namespace _private
    {
        class boolStringVec
        {
            friend class interpreter::commandList;
            boolStringVec() {};
            ~boolStringVec() {};

            void push_back( const std::string commandSet ) { strings.push_back( commandSet ); bools.push_back( false ); };
            const std::string getLast() { return strings[strings.size()-1]; };
            void setFinishedLast() { bools[bools.size()-1] = true; };
            const bool getFinished( unsigned int i ) { return bools[i]; };
            std::vector< std::string > strings;
            std::vector< bool > bools;
        };
    }

    class commandList
    {
        ~commandList() {};
        commandList() {};
        commandList * operator=( const commandList & ) {};
        commandList(const commandList &) {};
    public:
        static commandList & getList() { static commandList instance; return instance; };

        void push_back( const std::string commandSet ) { commands.push_back( commandSet ); };

    private:
        _private::boolStringVec commands;
    };
}

#endif // interpreterStack_hpp
