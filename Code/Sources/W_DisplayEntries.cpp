/*
Author: Mia Kelley-Lanser
Date: 05/07/2023
All rights reserved
*/

#include "W_DisplayEntries.h"
#include "ui_W_DisplayEntries.h"

#include <fstream>
#include <Qfile>
#include <QTextStream>
#include <QMessageBox>

W_DisplayEntries::W_DisplayEntries(UserDatabase* database, QString fileName, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::W_DisplayEntries)
{
    ui->setupUi(this);
    this->database = database;
    this->fileName = fileName;
}

W_DisplayEntries::~W_DisplayEntries()
{
    delete ui;
}

void W_DisplayEntries::on_pushButton_Display_clicked()
{
    QString category = ui->lineEdit_Category->text();

    std::fstream outFile;
    outFile.open(fileName.toStdString(), std::ofstream::out | std::ofstream::trunc); // trunc = delete contents of file before writing current ones so as to not repeat entries
    if (outFile.is_open()) {
        if(category == "") database->displayAllEntries(outFile);
        else {
            database->displayEntries(outFile, category.toStdString());
        }
    }
    else {
        QMessageBox::information(this, "Cannot find file to write.", "Error: Cannot find file.");
    }
    outFile.close();

   QFile displayFile(fileName);
   if (!displayFile.open(QIODevice::ReadOnly)) {
       QMessageBox::information(this, "Cannot find file to read.", "Error: Cannot find file.");
    }
   else {
       QTextStream in(&displayFile);
       ui->textBrowser_Entries->setFont(QFont("Courier", 10));
       ui->textBrowser_Entries->setText(in.readAll());
   }
}

