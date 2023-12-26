#include "W_DeleteEntry.h"
#include "ui_W_DeleteEntry.h"

#include <QMessageBox>

W_DeleteEntry::W_DeleteEntry(UserDatabase* database, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::W_DeleteEntry)
{
    ui->setupUi(this);
    this->database = database;
}

W_DeleteEntry::~W_DeleteEntry()
{
    delete ui;
}

void W_DeleteEntry::on_pushButton_Delete_clicked()
{
    QString type = ui->comboBox_Type->currentText();
    QString category = ui->lineEdit_Category->text();
    QString subcategory = ui->lineEdit_Subcategory->text();
    double amount = ui->doubleSpinBox_Amount->value();
    QDate date = ui->dateEdit->date();

    if (type == "Expense") amount *= -1.0;

    if (category == "") QMessageBox::information(this, "Invalid Category", "Category field is required.");
    else {
        bool failed = false;
        try {
            if (subcategory.toStdString() == "") database->deleteEntry(date.month(), date.day(), date.year(), category.toStdString(), amount);
            else database->deleteEntry(date.month(), date.day(), date.year(), category.toStdString(), subcategory.toStdString(), amount);
        } catch(std::invalid_argument e) {
            failed = true;
            QMessageBox::information(this, "Entry doesn't exist", e.what());
        }

        if (!failed) this->hide();
    }
}

