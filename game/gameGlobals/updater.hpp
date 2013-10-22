#ifndef updater_hpp
#define updater_hpp

#include <gameGlobals/updateable.hpp>
#include <vector>

class updater
{
private:
    ~updater() {};
    updater() {};
    updater * operator=( const updater & ) {};
    updater(const updater &) {};
public:
    static updater & getUpdater() { static updater instance; return instance; };

    void push_back( updateable & newUpdateable )
    {
        for( unsigned int i = 0; i < toUpdate.size(); i++ )
        {
            if( toUpdate[i] == &newUpdateable )
                return;
        }
        toUpdate.push_back( &newUpdateable );
    };

    bool remove( updateable & toRemove )
    {
        for( unsigned int i = 0; i < toUpdate.size(); i++ )
        {
            if( toUpdate[i] == &toRemove )
            {
                toUpdate.erase( toUpdate.begin() + i );
                return true;
            }
        }
        return false;
    };

    void update() { for( unsigned int i = 0; i < toUpdate.size(); i++ ) toUpdate[i]->update(); };

private:
    std::vector< updateable * > toUpdate;
};

#endif // updater_hpp
