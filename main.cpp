#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include<QMessageBox>
#include "tiffparser.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile tiffFile("/home/alex/Desktop/6010_0_0_A.tiff");
    if(!tiffFile.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0, "error", tiffFile.errorString());
    }
    QByteArray bytes;
    while (!tiffFile.atEnd())
    {
        bytes.append(tiffFile.readLine());
    }



    return a.exec();
}
