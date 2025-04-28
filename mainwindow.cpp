/*
 * Copyright (C) 2024 - 2025 Mikhail Medvedev <e-ink-reader@yandex.ru>
 *
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
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
    if ((name1.isEmpty() == false) and (name2.isEmpty() == false))
    {
        DialogCompare* compDialog = new DialogCompare();
        compDialog->show();
        compDialog->showArrays(&buf1, &buf2, &name1, &name2);
    }
    else
    {
        QMessageBox::about(this, tr("Error"), tr("This is nothing to compare with!\nPlease select `File1` and `File2` and press the `Compare` button again."));
        return;
    }
}
