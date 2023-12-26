#include "Menu.h"
#include "W_Login.h"
#include "ui_Menu.h"

#include <QMessageBox>
//#include <QLineSeries>
#include <fstream>

Menu::Menu(QString userDataFileName, QString financeFileName, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
    this->userDataFileName = userDataFileName;
    this->financeFileName = financeFileName;

    this->database = new UserDatabase;

        std::ifstream inFile;
        std::string input;

        inFile.open(financeFileName.toStdString());
        if (inFile.is_open()) {
            getline(inFile, input); // get rid of header line
            getline(inFile, input); // get rid of dashes

            Date date;
            std::string category = "";
            std::string subcategory = "";
            std::string str_amount;

          while (getline(inFile, input)) {
            bool valid = true;
            category = "";
            subcategory = "";
            str_amount = "";
            try {
              date.set(stoi(input.substr(0, 2)), stoi(input.substr(3, 5)), stoi(input.substr(6, 9)));
            } catch(Date::InvalidDate e) {
                  qDebug() << QString::fromStdString(e.getErrorType());
                  valid = false;
            }

            int i = 6;
            while(!isalpha(input[i])) i++;
            while (isalpha(input[i])) {
                category += input[i];
                i++;
            }
            while(!isalpha(input[i]) && !isdigit(input[i]) && input[i] != '-') i++;
            while (isalpha(input[i])) {
                subcategory += input[i];
                i++;
            }
            bool expense = false;
            if (input[i] == '-') {
                expense = true;
                i++;
            }
            while(!isdigit(input[i]) && input[i] != '-') i++;
            if (input[i] == '-') {
                expense = true;
                i++;
            }
            while (isdigit(input[i]) || input[i] == '.') {
                str_amount += input[i];
                i++;
            }
            double amount = stod(str_amount);
            if (expense) amount *= -1;
            if (valid) {
            try {
                database->createNewEntry(date.getMonth(), date.getDay(), date.getYear(), category, subcategory, amount);
            } catch(std::invalid_argument e) {
                qDebug () << e.what();
            }
            }
          }
        inFile.close();
        }
        else {
            QMessageBox::information(this, "Cannot find file to write.", "Error: Cannot find file. Could not import data. Changes may not be permanent.");
        }
}

Menu::~Menu()
{
    delete ui;
}


void Menu::on_pushButton_CreateNewCategory_clicked()
{
    w_cnc = new W_CreateNewCategory(database, this);
    w_cnc->show();
}


void Menu::on_pushButton_CreateNewEntry_clicked()
{
    w_cne = new W_CreateNewEntry(database, this);
    w_cne->show();
}


void Menu::on_pushButton_DeleteEntry_clicked()
{
    w_de = new W_DeleteEntry(database, this);
    w_de->show();
}


void Menu::on_pushButton_DisplayEntries_clicked()
{
    w_des = new W_DisplayEntries(database, financeFileName, this);
    w_des->show();
}


void Menu::on_pushButton_GenerateGraph_clicked()
{
    w_gg = new W_GenerateGraph(database, this);
    w_gg->show();
}


void Menu::on_pushButton_Logout_clicked()
{
    bool printed = false;
    std::fstream outFile;
    outFile.open(financeFileName.toStdString(), std::ofstream::out | std::ofstream::trunc); // trunc = delete contents of file before writing current ones so as to not repeat entries
    if (outFile.is_open()) {
        printed = true;
        database->displayAllEntries(outFile);
    }
    else {
        QMessageBox::information(this, "Cannot find file to write.", "Error: Cannot find file. Quitting will not save data.");
    }
    outFile.close();
    //if (printed) return QApplication::quit();
    if (printed) {
        this->hide();
        W_Login *returnLogin = new W_Login(userDataFileName, this);
        returnLogin->show();
    }
}
