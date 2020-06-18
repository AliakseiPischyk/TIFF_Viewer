
#include "TestTIFFParser.h"

#include <qbytearray.h>
#include "definesandenums.h"
#include <QtTest/QtTest>
#include "tiffparser.h"

QByteArray TestTIFFParser::makeII()
{
    QByteArray bytes;
    bytes.push_back(EnEndiannessLetterInTiff::I);
    bytes.push_back(EnEndiannessLetterInTiff::I);
    return bytes;
}

QByteArray TestTIFFParser::makeMM()
{
    QByteArray bytes;
    bytes.push_back(EnEndiannessLetterInTiff::M);
    bytes.push_back(EnEndiannessLetterInTiff::M);
    return bytes;
}

QByteArray TestTIFFParser::makeFromValues(const QVector<char> &bytes)
{
    QByteArray retBytes;
    for (char c : bytes)
    {
        retBytes.push_back(c);
    }
    return retBytes;
}

QByteArray TestTIFFParser::makeMMWithMagic()
{
     return makeMM().append(makeFromValues({0x00,0x2a}));
}

QByteArray TestTIFFParser::makeIIWithMagic()
{
    return makeII().append(makeFromValues({0x2a,0x00}));
}

void TestTIFFParser::EndiannessII()
{
    QCOMPARE(longCast(TIFFParser::getEndianness(makeII())),longCast(EnEndianness::END_LITTLE));
}

void TestTIFFParser::EndiannessMM()
{
    QCOMPARE(longCast(TIFFParser::getEndianness(makeMM())),longCast(EnEndianness::END_BIG));
}

void TestTIFFParser::EndiannessINotI()
{
    QByteArray bytes=makeFromValues({EnEndiannessLetterInTiff::I,EnEndiannessLetterInTiff::I^1});
    QCOMPARE(longCast(TIFFParser::getEndianness(bytes)),longCast(EnEndianness::END_EXCEPT));
}

void TestTIFFParser::EndiannessMNotM()
{
    QByteArray bytes=makeFromValues({EnEndiannessLetterInTiff::M,EnEndiannessLetterInTiff::M^1});
    QCOMPARE(longCast(TIFFParser::getEndianness(bytes)),longCast(EnEndianness::END_EXCEPT));
}

void TestTIFFParser::EndiannessNotMM()
{
    QByteArray bytes={EnEndiannessLetterInTiff::M^1,EnEndiannessLetterInTiff::M};
    QCOMPARE(longCast(TIFFParser::getEndianness(bytes)),longCast(EnEndianness::END_EXCEPT));
}

void TestTIFFParser::EndiannessNotII()
{
    QByteArray bytes=makeFromValues({EnEndiannessLetterInTiff::I^1,EnEndiannessLetterInTiff::I});
    QCOMPARE(longCast(TIFFParser::getEndianness(bytes)),longCast(EnEndianness::END_EXCEPT));
}

void TestTIFFParser::EndiannessDataSizeLessThen2()
{
    QCOMPARE(longCast(TIFFParser::getEndianness(makeFromValues({0x01}))),longCast(EnEndianness::END_EXCEPT));
}

    //magic number tests

void TestTIFFParser::MagicDataSizeLessThen4()
{
    QByteArray bytes="123";
    QCOMPARE(TIFFParser::isMagicNumberOk(bytes),false);
}

void TestTIFFParser::MagicOkEndiannessII()
{
  QCOMPARE(TIFFParser::isMagicNumberOk(makeIIWithMagic()),true);
}

void TestTIFFParser::MagicNotOkEndiannessII()
{
 QCOMPARE(TIFFParser::isMagicNumberOk(makeII().append(makeFromValues({0x22,0x33}))),false);
}

void TestTIFFParser::MagicOkEndiannessMM()
{
  QCOMPARE(TIFFParser::isMagicNumberOk(makeMMWithMagic()),true);
}

void TestTIFFParser::MagicNotOkEndiannessMM()
{
  QCOMPARE(TIFFParser::isMagicNumberOk(makeMM().append(makeFromValues({0x33,0x22}))),false);
}

void TestTIFFParser::MagicOkEndiannessNotOk()
{
    QCOMPARE(TIFFParser::isMagicNumberOk(makeFromValues({0x55,0x66}).append(makeFromValues({0x2a,0x00}))),false);
}

 //end magic number tests


//first IFD tests

void TestTIFFParser::getIFDFromHeaderDataSizeLessThen8()
{
    QCOMPARE(TIFFParser::getIFDFromHeader(makeIIWithMagic().append(makeFromValues({0x11,0x22}))),false);
}

void TestTIFFParser::getIFDFromHeaderMagicNotOk()
{

}

void TestTIFFParser::getIFDFromHeaderEndiannessII()
{

}

void TestTIFFParser::getIFDFromHeaderEndiannessMM()
{

}

void TestTIFFParser::getIFDFromHeaderEndiannessNotOk()
{

}
   //end first IFD tests


