#ifndef consoleDataGrabber_hpp
#define consoleDataGrabber_hpp

#include <iostream>
#include <string>

class windowConsole;
class consoleDataGrabber
{
    friend class windowConsole;
private:
    consoleDataGrabber() {};
    consoleDataGrabber( const consoleDataGrabber & conf ) {};
    consoleDataGrabber * operator=( const consoleDataGrabber & conf ) {};
    ~consoleDataGrabber() {};
public:
    static consoleDataGrabber & getDataBank() { static consoleDataGrabber instance; return instance; };

    void addLog( const std::string log ) { logs.push_back( log ); };
private:
    void removeLog( const std::string log ) { for( unsigned int i = 0; i < logs.size(); i++ ){ if( logs[i] == log ) logs.erase( logs.begin() + i ); } };
    void removeLog( const unsigned int i ) { logs.erase( logs.begin() + i ); };

    std::vector< std::string > & getLogs() { return logs; };
    std::vector< std::string > logs;
};

#endif // consoleDataGrabber_hpp
