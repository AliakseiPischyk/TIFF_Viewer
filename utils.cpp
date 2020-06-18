#include "utils.h"

unsigned int makeUnsignedIntFromBytes(char b1, char b2, char b3, char b4)
{
    return static_cast<unsigned int>(static_cast<unsigned int>(b1) << 24 |
                                        static_cast<unsigned char>(b2) << 16 |
                                        static_cast<unsigned char>(b3) << 8 |
                                        static_cast<unsigned char>(b4));
}

unsigned short makeUnsignedShortFromBytes(char b1, char b2)
{
    return static_cast<unsigned short>(static_cast<unsigned char>(b1 << 8 |
                                        static_cast<unsigned char>(b2)));
}


bool assertAndRet(const bool b)
{
    Q_ASSERT(b);
    return b;
}
