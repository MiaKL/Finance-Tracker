/*
Author: Mia Kelley-Lanser
Date: 05/07/2023
All rights reserved
*/

#ifndef W_LOGIN_H
#define W_LOGIN_H

#include <QMainWindow>
#include <QMessageBox>

#include "Menu.h"
#include "User.h"

namespace Ui {
class W_Login;
}

class W_Login : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief W_Login constructor, creates a new W_Login object and sets up the ui; sets this->userDataFileName to the given value
     * @param userDataFileName (name of text file where user login credentials are stored)
     * @param parent
     */
    explicit W_Login(QString userDataFileName, QWidget *parent = nullptr);
    ~W_Login();

private slots:
    /**
     * @brief executed when login button is clicked; checks if the given username and password pair exists in the user data file;
     * if they do, creates a new Menu window and passes the name of that user's file ("Finance_" + username) and hides this window;
     * if not, then lets the user know, prompting them to enter valid login credentials
     */
    void on_pushButton_login_clicked();

    /**
     * @brief executed when register button is clicked; checks if the given username already exists in the user data file; if it
     * does, lets the user know and prompts them to enter a different username; if not, then registers them, writing the new user
     * login credentials to the user data file and creates a new file for that user's finance data called "Finance_" + username,
     * then hides this window and creates a new Menu window and passes the name of the new user file to its constructor
     */
    void on_pushButton_register_clicked();

    /**
     * @brief executed when quit button is clicked; quits the application
     */
    void on_pushButton_quit_clicked();

private:
    Ui::W_Login *ui;
    QString userDataFileName;
};

#endif // W_LOGIN_H
