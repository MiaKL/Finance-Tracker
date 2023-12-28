/*
Author: Mia Kelley-Lanser
Date: 05/07/2023
All rights reserved
*/

#ifndef W_DISPLAYENTRIES_H
#define W_DISPLAYENTRIES_H

#include <QDialog>

#include "UserDatabase.h"

namespace Ui {
class W_DisplayEntries;
}

class W_DisplayEntries : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief W_DisplayEntries constructor; sets database, fileName, and parent to the given values
     * @param database
     * @param fileName
     * @param parent
     */
    explicit W_DisplayEntries(UserDatabase* database, QString fileName, QWidget *parent = nullptr);
    ~W_DisplayEntries();

private slots:
    /**
     * @brief When Display pushButton is clicked, the current value in the input in the ui is used to
     * display either all entries (if no value is given) or the entries under the category with the given title;
     * First, the contents of the file with fileName are overwritten with the current database, then the database
     * is read into the textBrowser so that the user can see them
     */
    void on_pushButton_Display_clicked();

private:
    Ui::W_DisplayEntries *ui;

    UserDatabase* database;
    QString fileName;
};

#endif // W_DISPLAYENTRIES_H
