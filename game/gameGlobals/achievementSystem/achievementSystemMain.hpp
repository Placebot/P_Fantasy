#ifndef achievementSystemMain_hpp
#define achievementSystemMain_hpp

#include <fileUtilities/serializeable.hpp>
#include <gameGlobals/specialAction/specialAction.hpp>

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

        static std::string getAchievementDesc( const std::string achName )
        {
            if( achName == "TEST" )
                return "TEST_DESCRIPTION";
        };

        void complete( const std::string achievement )
        {

        };

        void addNew( const std::string achName, const std::string achDesc )
        {
            notCompleted.push_back( achName );
            notCompletedDesc.push_back( achDesc );
        };

        // Derived from file::serializeable
        virtual const bool save( const std::string path )
        {

        };

        virtual const bool load(  const std::string path, bool directFromString = false )
        {

        };

    private:
        unsigned int _fitKey( const std::string & key )
        {
            for( unsigned int i = 0; i < actionKeys.size(); i++ )
            {
                if( key == actionKeys[i] )
                    return i;
            }
        };

        std::vector< std::string > completed;
        std::vector< std::string > completedDesc;

        std::vector< specialAction::action > actions;
        std::vector< std::string > actionKeys;

        std::vector< std::string > notCompleted;
        std::vector< std::string > notCompletedDesc;
    };
}

#endif // achievementSystemMain_hpp
