#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QByteArray buf1, buf2;
    QString name1, name2;

private slots:
    void on_pushButton_f1_clicked();
    void on_pushButton_f2_clicked();
    void on_pushButton_compare_clicked();

private:
    Ui::MainWindow *ui;
    QString lastDirectory;
    //QString fileName;
};

#endif // MAINWINDOW_H
