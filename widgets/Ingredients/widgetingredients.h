#ifndef WIDGETINGREDIENTS_H
#define WIDGETINGREDIENTS_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QAbstractTableModel;
class QPushButton;
class QTableView;
class QDialog;
QT_END_NAMESPACE

class Ingredient;

class WidgetIngredients : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetIngredients(QWidget *parent = nullptr);
private:
    void createUI();
    void createModel();
    void loadFromDB();

    void addIngredient();
    void updateIngredient();
    void removeIngredient(int id);

    Ingredient *getSelectedItem();

    QTableView *tv;
    QAbstractTableModel *modelTableIngredient;

    QPushButton *btnIngredientNew;
    QPushButton *btnIngredientEdit;
    QPushButton *btnIngredientRemove;

    Ingredient *currentIngredient;
    int maxID;

//    QDialog *dialogEditIngredient;

    QVector<Ingredient> *mData;

private slots:
    void slotAddIngredient();
    void slotEditIngredient();
    void slotRemoveIngredient();
};

#endif // WIDGETINGREDIENTS_H
