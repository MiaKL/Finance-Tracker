/*
Author: Mia Kelley-Lanser
Date: 05/07/2023
All rights reserved
*/

#ifndef W_CREATENEWENTRY_H
#define W_CREATENEWENTRY_H

#include <QDialog>

#include "UserDatabase.h"

namespace Ui {
class W_CreateNewEntry;
}

class W_CreateNewEntry : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief W_CreateNewEntry constructor; sets database and parent to the given values
     * @param database
     * @param parent
     */
    explicit W_CreateNewEntry(UserDatabase* database, QWidget *parent = nullptr);
    ~W_CreateNewEntry();

private slots:
    /**
     * @brief When Create pushButton is clicked, the current values in the inputs in the ui are used to
     * add an entry to the database
     */
    void on_pushButton_Create_clicked();

private:
    Ui::W_CreateNewEntry *ui;

    UserDatabase* database;
};

#endif // W_CREATENEWENTRY_H
