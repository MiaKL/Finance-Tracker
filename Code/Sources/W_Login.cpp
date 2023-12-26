#include "W_Login.h"
#include "ui_W_Login.h"

#include <fstream>
#include <QFile>

W_Login::W_Login(QString userDataFileName, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::W_Login)
{
    ui->setupUi(this);
    this->userDataFileName = userDataFileName;
}

W_Login::~W_Login()
{
    delete ui;
}

void W_Login::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    std::ifstream inFile(userDataFileName.toStdString());

     users::User myUser{"", "", 0};

     bool loggedIn = false;

     if (username == "") QMessageBox::information(this, "Username field required.", "Username field is required.");
     else if (password == "") QMessageBox::information(this, "Password field required.", "Password field is required.");
     else {
        while (!inFile.eof() && inFile >> myUser) {
            if(username == QString::fromStdString(myUser.getUserName()) && password == QString::fromStdString(myUser.getPassword())) {
                loggedIn = true;
                this->hide();

                QString financeFileName = "Finance_" + username;

                Menu *menu = new Menu(userDataFileName, financeFileName, this);
                menu->show();
             }
        };
        inFile.close();
        if (loggedIn == false) {
            QMessageBox::information(this, "Invalid username or password.", "Invalid username or password.");
        }
     }
}


void W_Login::on_pushButton_register_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    std::ifstream inFile(userDataFileName.toStdString());

     users::User myUser{"", "", 0};

     bool valid = true;
     int lastUserID = 999;

     if (username == "") QMessageBox::information(this, "Username field required.", "Username field is required.");
     else if (password == "") QMessageBox::information(this, "Password field required.", "Password field is required.");
     else {
         bool empty = false;
         inFile.seekg(0, std::ios::end);
         if (inFile.tellg() == 0) {
           empty = true;
         }
         inFile.seekg(0, std::ios::beg);
        if (!empty) {
            while (!inFile.eof() && inFile >> myUser) {
                if(username == QString::fromStdString(myUser.getUserName())) {
                    valid = false;
                }
                lastUserID = myUser.getUserID();
            }
         inFile.close();
        }
        if (valid == false) {
             QMessageBox::information(this, "Failed Registration", "Username already exists. Please enter a new username. \n\nSuggestion: " + username + "2");
        }
        else {
             std::ofstream outFile(userDataFileName.toStdString(), std::ios::app);
             int newUserID = ++lastUserID;

             users::User newUser(username.toStdString(), password.toStdString(), newUserID);
             outFile << newUser; // write user credentials to userData file

             QString financeFileName = "Finance_" + username;
             QFile file(financeFileName); // new file for new user's finance data
             file.open(QIODevice::ReadWrite);
             file.close();

             QMessageBox::information(this, "Successful Registration", "You have been registered and logged in to your new account.");
             this->hide();

             Menu *menu = new Menu(userDataFileName, financeFileName, this);
             menu->show();
            outFile.close();
        }
     }
}


void W_Login::on_pushButton_quit_clicked()
{
    QApplication::quit();
}

