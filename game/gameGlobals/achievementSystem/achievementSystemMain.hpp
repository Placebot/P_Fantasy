#ifndef achievementSystemMain_hpp
#define achievementSystemMain_hpp

#include <sstream>

#include <fileUtilities/serializeable.hpp>
#include <gameGlobals/achievementSystem/achievement.hpp>
#include <gameGlobals/topLevelGlobals.hpp>

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
            /// 0 - default
            ///
            /// Achievement saving ( 0 )
            /// syntax:
            /// earned;ID;
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
                        saver.addData( _achievements[i]._earned, _achievements[i]._myID );
                    }
                }
                std::stringstream ss;
                ss << ACHIEVEMENT_STRING_BEGIN << "_SAVE_MODE";
                std::string temp = ss.str();
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

        const bool addAchievement( achievements::achievement ach )
        {
            if( _fitKey( ach._myID, false ) == -1 )
            {
                _achievements.push_back( ach );
                return true;
            }
            else
            {
                consoleDataGrabber::getDataBank().addLog( "Achievement adding failed. Couldn't add achievement '" + ach._myName + "' with ID '" + ach._myID + "'." );
                return false;
            }
        };

        achievements::achievement & operator[]( const std::string & ID ) { return _achievements[ _fitKey(ID, false)]; };

    private:
        int _fitKey( const std::string & key, bool name )
        {
            for( unsigned int i = 0; i < _achievements.size(); i++ )
            {
                if( key == ( name ? _achievements[i]._myName : _achievements[i]._myID ) )
                    return i;
            }
            return -1;
        };

        std::vector< achievements::achievement > _achievements;
    };
}

#endif // achievementSystemMain_hpp
