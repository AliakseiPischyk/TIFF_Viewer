#ifndef QTIFF_PARSER_TESTER_H
#define QTIFF_PARSER_TESTER_H

#include <QObject>

class TestTIFFParser : public QObject
{
    Q_OBJECT
    QByteArray makeII();
    QByteArray makeMM();
    QByteArray makeFromValues(const QVector<char>& bytes);
    QByteArray makeMMWithMagic();
    QByteArray makeIIWithMagic();
private slots:
   //Endianness tests
   void EndiannessII();
   void EndiannessMM();
   void EndiannessINotI();
   void EndiannessMNotM();
   void EndiannessNotMM();
   void EndiannessNotII();
   void EndiannessDataSizeLessThen2();
   //endd endianness tests

   //magic number tests
   void MagicDataSizeLessThen4();
   void MagicOkEndiannessII();
   void MagicNotOkEndiannessII();
   void MagicOkEndiannessMM();
   void MagicNotOkEndiannessMM();
   void MagicOkEndiannessNotOk();
   //end magic number tests

   //first IFD tests
   void getIFDFromHeaderDataSizeLessThen8();
   void getIFDFromHeaderMagicNotOk();
   void getIFDFromHeaderEndiannessII();
   void getIFDFromHeaderEndiannessMM();
   void getIFDFromHeaderEndiannessNotOk();
   //end first IFD tests




};

#endif // QTIFF_PARSER_TESTER_H
