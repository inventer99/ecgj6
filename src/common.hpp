#pragma once

#ifdef GAME_PLATFORM_WINDOWS
    #ifdef GAME_IMPORT
        #define GAME_API __declspec(dllimport)
    #else
        #define GAME_API __declspec(dllexport)
    #endif
#else
    #define GAME_API
#endif
