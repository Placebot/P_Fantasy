#ifndef achievementSystemMain_hpp
#define achievementSystemMain_hpp

#include <sstream>

#include <fileUtilities/serializeable.hpp>
#include <gameGlobals/achievementSystem/achievement.hpp>
#include <gameGlobals/topLevelGlobals.hpp>
#include <gameGlobals/achievementSystem/achievementSystemActions.hpp>

namespace achievements
{
    class systemMain : public file::serializeable
    {
    private:
        ~systemMain() {};
        systemMain() {};
        systemMain * operator=( const systemMain & ) {};
        systemMain(const systemMain &) {};
    public:
        static systemMain & getSystem() { static systemMain instance; return instance; };

        bool complete( const std::string achName )
        {
            if( _achievements.size() )
            {
                for( unsigned int i = 0; i < _achievements.size(); i++ )
                {
                    if( _achievements[i]._myName == achName )
                    {
                        _achievements[i].complete();
                        return true;
                    }
                }
            }

            return false;
        };

        achievements::achievement & getAchievement( const std::string achName )
        {
            return _achievements[ _fitKey(achName, true) ];
        };

        achievements::achievement & getAchievementByID( const std::string achID )
        {
            return _achievements[ _fitKey(achID, false) ];
        };

        // Derived from file::serializeable
        virtual const bool save( const std::string path, unsigned int mode = 0 )
        {
            ///-----------------------
            /// Modes available:
            /// 0 - default, full save
            /// 1 - earned state / key, commands instead of function
            ///
            /// Achievement saving ( 0 )
            /// syntax:
            /// achievementName;ID;
            /// achievementDescription;ID;
            /// earned;ID;
            ///
            /// Achievement saving ( 1 )
            /// earned;ID;
            /// instructionSet;ID;
            ///
            /// function selected by ID
            ///
            /// mode saved in the end as
            /// ACH_SAVE_MODE;mode;
            ///-----------------------

            if( _achievements.size() )
            {
                file::save saver;
                if( mode == 0 )
                {
                    for( unsigned int i = 0; i < _achievements.size(); i++ )
                    {
                        saver.addData( _achievements[i]._myName, _achievements[i]._myID );
                        saver.addData( _achievements[i]._myDesc, _achievements[i]._myID );
                        saver.addData( _achievements[i]._earned, _achievements[i]._myID );
                    }
                }
                else if( mode == 1 )
                {
                    for( unsigned int i = 0; i < _achievements.size(); i++ )
                    {
                        saver.addData( _achievements[i]._earned, _achievements[i]._myID );
                        saver.addData( _achievements[i]._instructionSet, _achievements[i]._myID );
                    }
                }
                std::string temp = "ACH_SAVE_MODE";
                saver.addData( mode, temp );

                if( saver.saveToFile( path ) )
                    return true;
                else
                    return false;
            }
            else
                return false;
        };

        virtual const bool load(  const std::string path, bool directFromString = false )
        {
            file::load loader;
            if( !directFromString )
            {
                if( !loader.loadFromFile( path ) )
                    return false;
                else
                {
                    if( loader.size() )
                    {
                        unsigned int comp = 0, notComp = 0;
                        while( true )
                        {
                            bool test;
                        }
                    }
                    else
                        return false;
                }

            }
        };

        void addAchievement( achievements::achievement ach ) { _achievements.push_back( ach ); };

        achievements::achievement & operator[]( const std::string & ID ) { return _achievements[ _fitKey(ID, false)]; };

    private:
        const std::string getRest( unsigned int size )
        {
            size--;
            if( size == 0 )
                return "000";
            else
            {
                std::stringstream ss;
                std::string result;
                if( size >= 100 )
                {
                    ss << size;
                    ss >> result;
                    return result;
                }
                else if( size >= 10 )
                {
                    ss << size;
                    ss >> result;
                    return "0" + result;
                }
                else
                {
                    ss << size;
                    ss >> result;
                    return "00" + result;
                }
            }
        }

        bool checkName( const std::string name )
        {
            if( _achievements.size() )
            {
                for( unsigned int i = 0; i < _achievements.size(); i++ )
                    if( name == _achievements[i]._myName )
                        return true;
            }

            return false;
        };

        unsigned int _fitKey( const std::string & key, bool name )
        {
            for( unsigned int i = 0; i < _achievements.size(); i++ )
            {
                if( key == ( name ? _achievements[i]._myName : _achievements[i]._myID ) )
                    return i;
            }
        };

        std::vector< achievements::achievement > _achievements;
    };
}

#endif // achievementSystemMain_hpp
