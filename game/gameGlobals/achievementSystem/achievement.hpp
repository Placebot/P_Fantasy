#ifndef achievement_hpp
#define achievement_hpp

#include <gameGlobals/extend.hpp>

namespace achievements
{
    class systemMain;

    class achievement
    {
        friend class systemMain;
    public:
        achievement( const std::string achName, const std::string achDesc, const std::string ID )
        {
            _myName = achName;
            _myDesc = achDesc;
            _myID = ID;
        };

        ~achievement() {};

        const std::string getAchievementName() const { return _myName; };
        const std::string getAchievementDesc() const { return _myDesc; };

    private:
        void complete() { _earned = true; };

        std::string _myName = "MISSING_STRING";
        std::string _myDesc = "MISSING_DESCRIPTION";
        bool _earned = false;
        std::string _myID = "MISSING_ID";
    };
}

#endif // achievement_hpp
