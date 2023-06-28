#ifndef DIALOGINGREDIENTEDIT_H
#define DIALOGINGREDIENTEDIT_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QPushButton;
class QLineEdit;
QT_END_NAMESPACE

class Ingredient;

class DialogIngredientEdit : public QDialog
{
public:
    DialogIngredientEdit(Ingredient*);
private:
    void createUI();
    void fillUI();

    Ingredient *currentIngredient;

    QLineEdit *leName;
    QLineEdit *leWaist;
    QLineEdit *leProteins;
    QLineEdit *leFats;
    QLineEdit *leCarbons;
    QLineEdit *leEnergy;

    QPushButton *btnOk;
    QPushButton *btnCancel;
private slots:
    void onAccept();
};

#endif // DIALOGINGREDIENTEDIT_H
