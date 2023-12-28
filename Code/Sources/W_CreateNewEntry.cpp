/*
Author: Mia Kelley-Lanser
Date: 05/07/2023
All rights reserved
*/

#include "W_CreateNewEntry.h"
#include "ui_W_CreateNewEntry.h"

#include "UserDatabase.h"

#include <QMessageBox>

W_CreateNewEntry::W_CreateNewEntry(UserDatabase* database, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::W_CreateNewEntry)
{
    ui->setupUi(this);
    this->database = database;
}

W_CreateNewEntry::~W_CreateNewEntry()
{
    delete ui;
}

void W_CreateNewEntry::on_pushButton_Create_clicked()
{
    QString type = ui->comboBox_Type->currentText();
    QString category = ui->lineEdit_Category->text();
    QString subcategory = ui->lineEdit_Subcategory->text();
    double amount = ui->doubleSpinBox_Amount->value();
    QDate date = ui->dateEdit->date();

    if (type == "Expense") amount *= -1.0;

    if (category == "") QMessageBox::information(this, "Invalid Category", "Category field is required.");
    else {
        if (subcategory.toStdString() == "") database->createNewEntry(date.month(), date.day(), date.year(), category.toStdString(), amount);
        else database->createNewEntry(date.month(), date.day(), date.year(), category.toStdString(), subcategory.toStdString(), amount);
        this->hide();
    }
}

