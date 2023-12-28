/*
Author: Mia Kelley-Lanser
Date: 05/07/2023
All rights reserved
*/

#ifndef W_GENERATEGRAPH_H
#define W_GENERATEGRAPH_H

#include <QDialog>

#include "UserDatabase.h"

namespace Ui {
class W_GenerateGraph;
}

class W_GenerateGraph : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief W_DisplayEntries constructor; sets database and parent to the given values;
     * calls makePlot method wtih no argument (defaults to "") so that a graph is made
     * and shown of all income and expenses over time
     *
     * @param database
     * @param parent
     */
    explicit W_GenerateGraph(UserDatabase* database, QWidget *parent = nullptr);
    ~W_GenerateGraph();

private slots:
    /**
     * @brief When the Display button is clicked, clears the graph and calls makePlot
     * method with the category in the ui line-edit
     */
    void on_pushButton_Display_clicked();

private:
    Ui::W_GenerateGraph *ui;
    UserDatabase* database;

    /**
     * @brief Makes a graph of the income and expenses over time in the given category
     * (if no category is given, displays data in all categories)
     *
     * @param category
     */
    void makePlot(QString category = "");
};

#endif // W_GENERATEGRAPH_H
