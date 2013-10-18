#ifndef topLevelGlobals_hpp
#define topLevelGlobals_hpp

#define ACHIEVEMENT_STRING_BEGIN "ACH"
#define FUNCTION_STRING_BEGIN "FNC"

typedef void (* functionPointer)();

#define GET_WINDOW_RECTANGLE gameState::config::getConfig().getWindowRectangle()

#endif // top_level_globals_hpp
