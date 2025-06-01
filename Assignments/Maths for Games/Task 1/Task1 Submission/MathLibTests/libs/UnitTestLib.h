#pragma once

//#include "../../C++ Unit test - TEACHER ONLY/Colour.h"

namespace UnitLib
{
    using byte = unsigned char;

    unsigned int BuildColour(byte r, byte g, byte b, byte a);
    
    byte GetRed(unsigned int colour);
    byte GetGreen(unsigned int colour);
    byte GetBlue(unsigned int colour);
    byte GetAlpha(unsigned int colour);
}