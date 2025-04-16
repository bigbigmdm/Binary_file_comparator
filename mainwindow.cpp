#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogcompare.h"
#include <QLabel>
#include <QMessageBox>
#include <QErrorMessage>
#include <QDragEnterEvent>
#include <QtGui>
#include <QFileInfo>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    lastDirectory = QDir::homePath(); //"/home/";
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_f1_clicked()
{
    ui->statusBar->showMessage(tr("Opening file"));

        name1 = QFileDialog::getOpenFileName(this,
                                    QString(tr("Open file")),
                                    lastDirectory,
                                    "Data Images (*.bin *.BIN);;All files (*.*)");
    QFileInfo info(name1);
    ui->label_1->setText(info.fileName());
    lastDirectory = info.filePath();
    QFile file(name1);
    if (!file.open(QIODevice::ReadOnly))
    {
        return;
    }
    buf1.resize(static_cast<int>(info.size()));
    buf1 = file.readAll();
    file.close();
    ui->statusBar->showMessage(tr(""));
}

void MainWindow::on_pushButton_f2_clicked()
{
    ui->statusBar->showMessage(tr("Opening file"));

        name2 = QFileDialog::getOpenFileName(this,
                                    QString(tr("Open file")),
                                    lastDirectory,
                                    "Data Images (*.bin *.BIN);;All files (*.*)");
    QFileInfo info(name2);
    ui->label_2->setText(info.fileName());
    lastDirectory = info.filePath();
    QFile file(name2);
    if (!file.open(QIODevice::ReadOnly))
    {
        return;
    }
    buf2.resize(static_cast<int>(info.size()));
    buf2 = file.readAll();
    file.close();
    ui->statusBar->showMessage(tr(""));
}

void MainWindow::on_pushButton_compare_clicked()
{
    DialogCompare* compDialog = new DialogCompare();
        compDialog->show();
        compDialog->showArrays(&buf1, &buf2, &name1, &name2);
}
