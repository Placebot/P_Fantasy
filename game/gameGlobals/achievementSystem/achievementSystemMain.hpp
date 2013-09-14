#ifndef achievementSystemMain_hpp
#define achievementSystemMain_hpp

#include <fileUtilities/serializeable.hpp>

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

        void complete( const std::string achievemnt )
        {

        };

        // Derived from file::serializeable
        virtual const bool save( const std::string path )
        {

        };

        virtual const bool load(  const std::string path, bool directFromString = false )
        {

        };

    private:
        std::vector< std::string > completed;
        std::vector< std::string > notCompleted;
    };
}

#endif // achievementSystemMain_hpp
