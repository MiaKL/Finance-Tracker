#include "W_GenerateGraph.h"
#include "ui_W_GenerateGraph.h"

W_GenerateGraph::W_GenerateGraph(UserDatabase* database, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::W_GenerateGraph)
{
    ui->setupUi(this);
    this->database = database;
    makePlot();
}

W_GenerateGraph::~W_GenerateGraph()
{
    delete ui;
}

void W_GenerateGraph::makePlot(QString category) {
    std::vector<Entry> entries = database->getEntries();

    std::vector<double> uniqueDates;
    std::vector <double> dateAmounts;

    Date curDate;
    int curDateIndex = 0;

    if (entries.size() > 0) {
    for (int i = 0; i < int(entries.size()); i++) {
        if (category == "" || entries[i].getCategory() == category.toStdString()) {
        curDate = entries[i].getDate();
        if (i == 0) {
            uniqueDates.push_back(QDateTime::fromString(QString::fromStdString(curDate.toString()), "MM/dd/yyyy").toSecsSinceEpoch());
            dateAmounts.push_back(entries[i].getAmount());
        }
        else {
            if (curDate != entries[i-1].getDate()) {
                uniqueDates.push_back(QDateTime::fromString(QString::fromStdString(curDate.toString()), "MM/dd/yyyy").toSecsSinceEpoch());
                dateAmounts.push_back(entries[i].getAmount());
                curDateIndex = i;
            }
            else {
                dateAmounts[curDateIndex] += entries[i].getAmount();
            }
        }
        }
    }
    }

    QVector<double> x(uniqueDates.size()), y(dateAmounts.size());

    double minAmount = 0, maxAmount = 0;
    if (dateAmounts.size() > 0) {
        minAmount = dateAmounts[0];
        maxAmount = dateAmounts[0];
    }
    for (int i = 0; i < int(uniqueDates.size()); i++) {
        x[i] = uniqueDates[i];
        y[i] = dateAmounts[i];
        if (dateAmounts[i] < minAmount) {
            minAmount = dateAmounts[i];
        }
        if (dateAmounts[i] > maxAmount) {
            maxAmount = dateAmounts[i];
        }
    }

    ui->widget_qcustomplot->addGraph();
    ui->widget_qcustomplot->graph()->setData(x, y);
    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
    dateTicker->setDateTimeFormat("MM/dd/yyyy");
    ui->widget_qcustomplot->xAxis->setTicker(dateTicker);
    if (x.size() == 0) {
        ui->widget_qcustomplot->xAxis->setRange(0, 500);
    }
    else {
        // extra space around edges (24 hours):
        double datePadding = 24 * 3600;
        ui->widget_qcustomplot->xAxis->setRange(x.first() - datePadding, x.last() + datePadding);
    }
    // extra space around edges (10 percent of range):
    double amountPadding = abs(minAmount + maxAmount) / 10;
    ui->widget_qcustomplot->yAxis->setRange(minAmount - amountPadding, maxAmount + amountPadding);
    ui->widget_qcustomplot->plotLayout()->insertRow(0);
    QString title;
    if (category == "") {
        title = "Fluctuation of All Income and Expenses Over Time";
    }
    else {
        title = "Fluctuation of " + category + " Income and Expenses Over Time";
    }
    ui->widget_qcustomplot->plotLayout()->addElement(0, 0, new QCPTextElement(ui->widget_qcustomplot, title));
    ui->widget_qcustomplot->replot();
}

void W_GenerateGraph::on_pushButton_Display_clicked()
{
    QString category = ui->lineEdit_Category->text();
    ui->widget_qcustomplot->graph()->data()->clear();
    ui->widget_qcustomplot->plotLayout()->remove(ui->widget_qcustomplot->plotLayout()->element(0,0));
    ui->widget_qcustomplot->plotLayout()->simplify();
    makePlot(category);
}

