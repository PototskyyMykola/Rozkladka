#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QMdiArea;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    void createUI();
    void createActions();
    void createMenus();
    void updeteMenus();
    void updateToolBar();

    QWidget *widgetAnalysisList;
    QWidget *widgetIngredients;

    QMdiArea *mdiArea;
    QMenu *menu;
    QToolBar *toolbar;

    QAction *actionCreateWidgetAnalysisList;
    QAction *actionCreateWidgetIngredients;
private slots:
    void createWidgetAnalysisList();
    void createWidgetIngredients();

};
#endif // MAINWINDOW_H
