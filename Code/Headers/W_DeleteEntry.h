/*
 * Author: Mia Kelley-Lanser
 * Class: Advanced C++
 * Date: 05/07/2023
*/

#ifndef W_DELETEENTRY_H
#define W_DELETEENTRY_H

#include <QDialog>

#include "UserDatabase.h"

namespace Ui {
class W_DeleteEntry;
}

class W_DeleteEntry : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief W_DeleteEntry constructor; sets database and parent to the given values
     * @param database
     * @param parent
     */
    explicit W_DeleteEntry(UserDatabase* database, QWidget *parent = nullptr);
    ~W_DeleteEntry();

private slots:
    /**
     * @brief When Delete pushButton is clicked, the current values in the inputs in the ui are used to
     * search for an entry in the database with the same values; if the entry exists, it is removed from the
     * database
     */
    void on_pushButton_Delete_clicked();

private:
    Ui::W_DeleteEntry *ui;

    UserDatabase* database;
};

#endif // W_DELETEENTRY_H
