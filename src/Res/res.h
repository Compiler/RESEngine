#pragma once
#include <stdint.h>
#ifdef DEBUG_BUILD
#include <Res/Tools/Logging/FastLogger.h>
#endif
namespace res{
    extern float  DELTA_TIME;
    extern int    CUR_FPS;
    extern float  SCREEN_LEFT;
    extern float  SCREEN_RIGHT;
    extern float  SCREEN_BOTTOM;
    extern float  SCREEN_TOP;
    extern double MAX_FPS;
}