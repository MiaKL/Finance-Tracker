/*
 * Author: Mia Kelley-Lanser
 * Class: Advanced C++
 * Date: 05/07/2023
*/

#ifndef MENU_H
#define MENU_H

#include <QMainWindow>

#include "UserDatabase.h"

#include "W_CreateNewCategory.h"
#include "W_CreateNewEntry.h"
#include "W_DeleteEntry.h"
#include "W_DisplayEntries.h"
#include "W_GenerateGraph.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Menu; }
QT_END_NAMESPACE

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Menu constructor; sets  userDataFileName, FinanceFileName, and parent to the given values; reads the file with
     * the given name and stores data into database
     * @param userDataFileName
     * @param financeFileName
     * @param parent
     */
    Menu(QString userDataFileName, QString financeFileName, QWidget *parent = nullptr);
    ~Menu();

private slots:
    /**
     * @brief When CreateNewCategory pushButton is clicked, a new W_CreateNewCategory object is constructed and shown
     */
    void on_pushButton_CreateNewCategory_clicked();
    /**
     * @brief When DisplayEntries pushButton is clicked, a new W_DisplayEntries object is constructed and shown
    */
    void on_pushButton_DisplayEntries_clicked();
    /**
     * @brief When CreateNewEntry pushButton is clicked, a new W_CreateNewEntry object is constructed and shown
     */
    void on_pushButton_CreateNewEntry_clicked();
    /**
     * @brief When DeleteEntry pushButton is clicked, a new W_DeleteEntry object is constructed and shown
     */
    void on_pushButton_DeleteEntry_clicked();
    /**
     * @brief When GenerateGraph pushButton is clicked, a new W_GenerateGraph object is constructed and shown
    */
    void on_pushButton_GenerateGraph_clicked();
    /**
     * @brief When Logout pushButton is clicked, the current database is written to the file called
     * financeFileName, this window is hidden, and a new W_Login window is constructed and shown
     */
    void on_pushButton_Logout_clicked();

private:
    Ui::Menu *ui;

    UserDatabase* database;
    QString financeFileName;
    QString userDataFileName;

    W_CreateNewCategory *w_cnc;
    W_CreateNewEntry *w_cne;
    W_DeleteEntry *w_de;
    W_DisplayEntries *w_des;
    W_GenerateGraph *w_gg;
};
#endif // MENU_H
