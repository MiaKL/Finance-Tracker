/*
 * Author: Mia Kelley-Lanser
 * Class: Advanced C++
 * Date: 05/07/2023
*/

#ifndef W_CREATENEWCATEGORY_H
#define W_CREATENEWCATEGORY_H

#include <QDialog>

#include "UserDatabase.h"

namespace Ui {
class W_CreateNewCategory;
}

class W_CreateNewCategory : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief W_CreateNewCategory constructor; sets database and parent to the given values
     * @param database
     * @param parent
     */
    explicit W_CreateNewCategory(UserDatabase* database, QWidget *parent = nullptr);
    ~W_CreateNewCategory();

private slots:
    /**
     * @brief When Create pushButton is clicked, the current values in the inputs in the ui are used to
     * add a category to the database
     */
    void on_pushButton_Create_clicked();

private:
    Ui::W_CreateNewCategory *ui;

    UserDatabase* database;
};

#endif // W_CREATENEWCATEGORY_H
