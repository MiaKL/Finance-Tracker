/*
Author: Mia Kelley-Lanser
Date: 05/07/2023
All rights reserved
*/

#include "W_CreateNewCategory.h"
#include "ui_W_CreateNewCategory.h"

#include <QMessageBox>

W_CreateNewCategory::W_CreateNewCategory(UserDatabase* database, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::W_CreateNewCategory)
{
    ui->setupUi(this);
    this->database = database;
}

W_CreateNewCategory::~W_CreateNewCategory()
{
    delete ui;
}

void W_CreateNewCategory::on_pushButton_Create_clicked()
{
    QString title = ui->lineEdit_Title->text();
    QString subcategory = ui->lineEdit_Subcategory->text();

    if (title == "") QMessageBox::information(this, "Invalid Title", "Title field is required.");
    else {
        bool created = true;
        try {
            if (subcategory.toStdString() == "") database->createNewCategory(title.toStdString());
            else database->createNewSubcategory(title.toStdString(), subcategory.toStdString());
        } catch (std::invalid_argument e) {
            created = false;
            QMessageBox::information(this, "Invalid category or subcategory.", e.what());
        }
        if (created) this->hide();
    }
}

