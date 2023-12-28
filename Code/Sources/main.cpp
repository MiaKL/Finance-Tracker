/*
Author: Mia Kelley-Lanser
Date: 05/07/2023
All rights reserved
*/

#include "W_Login.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    // name of file where user data (login credentials) is stored
    //QString userDataFileName = "userLogins.txt";
    QString userDataFileName = "test_encrypt.txt";


    QApplication a(argc, argv);
    W_Login login(userDataFileName);
    login.show();
    return a.exec();
}
