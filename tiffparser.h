#ifndef TIFF_PARSER_H
#define TIFF_PARSER_H
#include "definesandenums.h"

class QByteArray;
class IFD;

class TIFFParser
{
public:
    TIFFParser();
    static EnEndianness getEndianness(const QByteArray& bytes) noexcept;
    static bool isMagicNumberOk(const QByteArray& bytes)noexcept;
    //IFD -- image file directory
    //returns first IFD
    //it points to 0 if error
    static IFD getIFDFromHeader(const QByteArray& bytes);
    //returns 0 if error
    static unsigned short getNumberOfDirectoryEntries(const IFD& ifd, const EnEndianness endianness);
};

#endif // TIFF_PARSER_H
