#ifndef achievement_hpp
#define achievement_hpp

#include <gameGlobals/extend.hpp>

namespace achievements
{
    class systemMain;

    class achievement : public extend::pointable
    {
        friend class systemMain;
    public:
        achievement( const std::string achName, const std::string achDesc, const std::string ID,functionPointer pointTo )
        {
            _myName = achName;
            _myDesc = achDesc;
            _myAction = pointTo;
        };
        ~achievement() {};

        virtual functionPointer getAction() { return _myAction; };

        virtual void setAction( functionPointer pointTo ) { _myAction = pointTo; };

        virtual const bool callAction()
        {
            if( _myAction != NULL )
            {
                _myAction();
                return true;
            }
            else
                return false;
        };

        const std::string getAchievementName() const { return _myName; };
        const std::string getAchievementDesc() const { return _myDesc; };

    private:
        void complete() { _earned = true; callAction(); };

        functionPointer _myAction = NULL;
        std::string _myName = "MISSING_STRING";
        std::string _myDesc = "MISSING_DESCRIPTION";
        bool _earned = false;
        std::string _myID = "MISSING_ID";
        std::string _instructionSet = "NULL";
    };
}

#endif // achievement_hpp
