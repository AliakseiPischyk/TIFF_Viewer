#ifndef DEFINESANDENUMS_H
#define DEFINESANDENUMS_H

enum EnEndiannessLetterInTiff : char
{
    I = 0x49,
    M = 0x4d
};

enum EnEndianness
{
    END_EXCEPT,
    END_LITTLE,
    END_BIG
};

#define longCast(enumValue) (static_cast<long>(enumValue))


#endif // DEFINESANDENUMS_H
