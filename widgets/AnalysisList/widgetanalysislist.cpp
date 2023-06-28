#include <QtWidgets>

#include "widgetanalysislist.h"
#include "dialogs/dialoganalysisedit.h"
#include "models/modelanalysislist.h"
#include "analysis.h"

WidgetAnalysisList::WidgetAnalysisList(QWidget *parent)
    : QWidget{parent}
{
    createModel();
    createUI();
    currentAnalysis = new Analysis;
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
    connect(btnAnalysisNew, &QPushButton::clicked, this, &WidgetAnalysisList::slotNewAanalysis);

    btnAnalysisEdit = new QPushButton(tr("Edit analysis"));
    btnAnalysisRemove = new QPushButton(tr("Remove analysis"));
    btnAnalysisPrint = new QPushButton(tr("Print analysis"));

    QVBoxLayout *buttonsLayout = new QVBoxLayout;
    buttonsLayout->addWidget(btnAnalysisNew);
    buttonsLayout->addWidget(btnAnalysisEdit);
    buttonsLayout->addWidget(btnAnalysisRemove);
    buttonsLayout->addWidget(btnAnalysisPrint);
    buttonsLayout->addStretch();

    widgetLayout->addWidget(tv);
    widgetLayout->addLayout(buttonsLayout);
}

void WidgetAnalysisList::createModel()
{
    modelTableAnalysis = new ModelAnalysisList(this);
}

void WidgetAnalysisList::slotNewAanalysis()
{
    currentAnalysis->clear();
    currentAnalysis->setID(++maxId);

    DialogAnalysisEdit dialogNew(currentAnalysis);
    dialogNew.exec();
}
