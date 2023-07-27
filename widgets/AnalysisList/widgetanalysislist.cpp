#include <QtWidgets>
#include <QSqlQuery>

#include "widgetanalysislist.h"
#include "dialogs/dialoganalysisedit.h"
#include "dialogs/dialogreceiptedit.h"
#include "viewmodels/modelanalysislist.h"
#include "datamodels/analysis.h"

WidgetAnalysisList::WidgetAnalysisList(QWidget *parent)
    : QWidget{parent}
{
    mData = new QVector<Analysis>;
    createModel();
    loadFromDB();

    createUI();
    currentAnalysis = new Analysis;
}

void WidgetAnalysisList::analysisEdit()
{

}

void WidgetAnalysisList::createUI()
{
    QHBoxLayout *widgetLayout = new QHBoxLayout;
    setLayout(widgetLayout);

    tv = new QTableView;
    tv->setModel(modelTableAnalysis);
    tv->setSelectionBehavior(QAbstractItemView::SelectRows);  // set selection to row
    tv->setSelectionMode(QAbstractItemView::SingleSelection); // set selection to only 1 row
    tv->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    tv->selectRow(0);

    btnAnalysisNew = new QPushButton(tr("Add analysis"));
    connect(btnAnalysisNew, &QPushButton::clicked, this, &WidgetAnalysisList::slotAanalysisNew);

    btnAnalysisEdit = new QPushButton(tr("Edit analysis"));
    connect(btnAnalysisEdit, &QPushButton::clicked, this, &WidgetAnalysisList::slotAnalysisEdit);

    btnAnalysisRemove = new QPushButton(tr("Remove analysis"));
    connect(btnAnalysisRemove, &QPushButton::clicked, this, &WidgetAnalysisList::slotAnalysisRemove);

    btnAnalysisView = new QPushButton(tr("View analysis"));
    connect(btnAnalysisView, &QPushButton::clicked, this, &WidgetAnalysisList::slotAnalysisView);

    btnAnalysisPrint = new QPushButton(tr("Print analysis"));
    connect(btnAnalysisPrint, &QPushButton::clicked, this, &WidgetAnalysisList::slotAnalysisPrint);

    QVBoxLayout *buttonsLayout = new QVBoxLayout;
    buttonsLayout->addWidget(btnAnalysisNew);
    buttonsLayout->addWidget(btnAnalysisEdit);
    buttonsLayout->addWidget(btnAnalysisRemove);
    buttonsLayout->addWidget(btnAnalysisView);
    buttonsLayout->addWidget(btnAnalysisPrint);
    buttonsLayout->addStretch();

    widgetLayout->addWidget(tv);
    widgetLayout->addLayout(buttonsLayout);
}

void WidgetAnalysisList::createModel()
{
    modelTableAnalysis = new ModelAnalysisList(mData, this);
}

void WidgetAnalysisList::loadFromDB()
{
    QSqlQuery query;
    query.exec("SELECT id, instance, dishname, date, weight FROM analysis");
    while(query.next()){
        Analysis analysis;
        analysis.setID(query.value(0).toInt());
        analysis.setIstance(query.value(1).toString());
        analysis.setDishName(query.value(2).toString());
        analysis.setDate(query.value(3).toDate());
        analysis.setWeight(query.value(4).toFloat());
        mData->append(analysis);
    }

    query.exec("SELECT MAX(id) FROM analysis");
    query.next();
    maxId = query.value(0).toInt();

}

Analysis *WidgetAnalysisList::getSelectedAnalysis()
{
    const QModelIndex index = tv->selectionModel()->currentIndex();
    int selectedRow = index.row();
    QVector<Analysis>::Iterator i = mData->begin();
    return i+selectedRow;
}

void WidgetAnalysisList::slotAanalysisNew()
{
    currentAnalysis->clear();
    currentAnalysis->setID(++maxId);

    DialogAnalysisEdit dialogNew(currentAnalysis);
    if(dialogNew.exec()){
        DialogReceiptEdit dialogNewReceipt(currentAnalysis);
        dialogNewReceipt.exec();
    }
}

void WidgetAnalysisList::slotAnalysisEdit()
{
    currentAnalysis = getSelectedAnalysis();
//    currentAnalysis->
    qDebug() << "Widget AnalysisList -> dialog analysisEdit with ID=" << currentAnalysis->getID();
    DialogAnalysisEdit dialogEdit(currentAnalysis);
    if(dialogEdit.exec()){
        qDebug() << "Widget AnalysisList -> dialog receiptEdit with ID=" << currentAnalysis->getID();
        currentAnalysis->getReceiptFromDB();
        DialogReceiptEdit dialogReceiptEdit(currentAnalysis);
        qDebug() << "Widget AnalysisList -> dialog created";
        dialogReceiptEdit.exec();
        qDebug() << "Widget AnalysisList -> dialog executed";
    }
}

void WidgetAnalysisList::slotAnalysisRemove()
{

}

void WidgetAnalysisList::slotAnalysisView()
{

}

void WidgetAnalysisList::slotAnalysisPrint()
{

}
