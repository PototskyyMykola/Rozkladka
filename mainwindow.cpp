#include <QtWidgets>

#include "mainwindow.h"
#include "widgets/AnalysisList/widgetanalysislist.h"
#include "widgets/Ingredients/widgetingredients.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    widgetAnalysisList = nullptr;
    widgetIngredients = nullptr;
    createUI();
    createActions();
}

MainWindow::~MainWindow()
{
}

void MainWindow::createUI()
{
    setWindowTitle(tr("Analysis Editor v.3.00 a"));

    mdiArea = new QMdiArea(this);
    mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setCentralWidget(mdiArea);
}

void MainWindow::createActions()
{
    QMenu *actionMenu = menuBar()->addMenu(tr("&Actions"));
    QToolBar *actionToolBar = addToolBar(tr("Actions"));

    actionCreateWidgetAnalysisList = new QAction(tr("Show Analysis"), this);
    connect(actionCreateWidgetAnalysisList, &QAction::triggered, this, &MainWindow::createWidgetAnalysisList);
    actionMenu->addAction(actionCreateWidgetAnalysisList);
    actionToolBar->addAction(actionCreateWidgetAnalysisList);

    actionCreateWidgetIngredients = new QAction(tr("Show Ingredients"), this);
    connect(actionCreateWidgetIngredients, &QAction::triggered, this, &MainWindow::createWidgetIngredients);
    actionMenu->addAction(actionCreateWidgetIngredients);
    actionToolBar->addAction(actionCreateWidgetIngredients);
}

void MainWindow::createWidgetAnalysisList()
{
    if(widgetAnalysisList == nullptr){
        widgetAnalysisList = new WidgetAnalysisList(this);
        mdiArea->addSubWindow(widgetAnalysisList);
        widgetAnalysisList->show();
    }
}

void MainWindow::createWidgetIngredients()
{
    if(widgetIngredients == nullptr){
        widgetIngredients = new WidgetIngredients(this);
        mdiArea->addSubWindow(widgetIngredients);
        widgetIngredients->show();
    }
}

