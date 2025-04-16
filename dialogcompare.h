#ifndef DIALOGCOMPARE_H
#define DIALOGCOMPARE_H

#include <QDialog>
#include <QResizeEvent>
#include "qhexedit.h"

namespace Ui {
class DialogCompare;
}

class DialogCompare : public QDialog
{
    Q_OBJECT

private slots:
    void handleScroll1();
    void handleScroll2();

public:
    explicit DialogCompare(QWidget *parent = nullptr);
    void showArrays(QByteArray *array1, QByteArray *array2, QString *name1, QString *name2);
    ~DialogCompare();

private:
    Ui::DialogCompare *ui;
    void resizeEvent(QResizeEvent* event);
    QString getCRC32(QByteArray buf);
    QString hexiAddr(uint32_t add);
    QString printAddress(int address, int digits);
    QString bytePrint(unsigned char z);
    QHexEdit *hexEdit1, *hexEdit2;
    QByteArray data1, data2;
    //QByteArray arr1, arr2;
};

#endif // DIALOGCOMPARE_H
