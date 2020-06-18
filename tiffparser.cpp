#include "tiffparser.h"
#include "utils.h"
#include <qbytearray.h>
#include "ifd.h"

TIFFParser::TIFFParser()
{

}

EnEndianness TIFFParser::getEndianness(const QByteArray &bytes)noexcept
{
    const char I = EnEndiannessLetterInTiff::I;
    const char M = EnEndiannessLetterInTiff::M;

    return bytes.size()>=2
            ?((bytes[0] == I && bytes[1] == I)
            ?EnEndianness::END_LITTLE
            :(bytes[0] == M && bytes[1] == M)
            ?EnEndianness::END_BIG
                :EnEndianness::END_EXCEPT)
            :EnEndianness::END_EXCEPT;
    }

bool TIFFParser::isMagicNumberOk(const QByteArray &bytes)noexcept
{
    if (bytes.size()<4)
    {
        return false;
    }

    const EnEndianness endianness = getEndianness(bytes);

    return endianness == EnEndianness::END_LITTLE
        ?(bytes[2]==0x2a && bytes[3]==0x0)
        :endianness == EnEndianness::END_BIG
            ?(bytes[2]==0x0 && bytes[3]==0x2a)
            :assertAndRet(false);
}

IFD TIFFParser::getIFDFromHeader(const QByteArray &bytes)
{
    if (bytes.size()<8 || !isMagicNumberOk(bytes))
    {
        return 0;
    }

    const EnEndianness endianness = getEndianness(bytes);

    return IFD(endianness == EnEndianness::END_BIG
            ?makeUnsignedIntFromBytes(bytes[4],bytes[5],bytes[6],bytes[7])
            :endianness == EnEndianness::END_LITTLE
                ?makeUnsignedIntFromBytes(bytes[7],bytes[6],bytes[5],bytes[4])
                :0);
}

unsigned short TIFFParser::getNumberOfDirectoryEntries(const IFD& ifd, const EnEndianness endianness)
{
    return endianness == EnEndianness::END_BIG
            ?makeUnsignedShortFromBytes(ifd.getDataPtr()[0],ifd.getDataPtr()[1])
            :endianness == EnEndianness::END_LITTLE
                ?makeUnsignedShortFromBytes(ifd.getDataPtr()[1],ifd.getDataPtr()[0])
                :0;
}
