#ifndef console_data_grabber_hpp
#define console_data_grabber_hpp

#include <iostream>
#include <string>

class windowConsole;
class console_data_grabber
{
    friend class windowConsole;
private:
    console_data_grabber() {};
    console_data_grabber( const console_data_grabber & conf ) {};
    console_data_grabber * operator=( const console_data_grabber & conf ) {};
    ~console_data_grabber() {};
public:
    static console_data_grabber & getDataBank() { static console_data_grabber instance; return instance; };

    void addLog( const std::string log ) { logs.push_back( log ); };
private:
    void removeLog( const std::string log ) { for( unsigned int i = 0; i < logs.size(); i++ ){ if( logs[i] == log ) logs.erase( logs.begin() + i ); } };
    void removeLog( const unsigned int i ) { logs.erase( logs.begin() + i ); };

    std::vector< std::string > & getLogs() { return logs; };
    std::vector< std::string > logs;
};

#endif // console_data_grabber_hpp
