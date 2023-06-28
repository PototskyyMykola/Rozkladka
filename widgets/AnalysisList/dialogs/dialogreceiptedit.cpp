#include <QtWidgets>

#include "dialogreceiptedit.h"
#include "../analysis.h"

DialogReceiptEdit::DialogReceiptEdit(Analysis *analysis)
{
    currentAnalysis = analysis;
}

void DialogReceiptEdit::createUI()
{
    QHBoxLayout *widgetLayout = new QHBoxLayout;
    setLayout(widgetLayout);


}
