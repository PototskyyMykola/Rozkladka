QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    widgets/AnalysisList/analysis.cpp \
    widgets/AnalysisList/dialogs/dialoganalysisedit.cpp \
    widgets/AnalysisList/dialogs/dialoganalysispreview.cpp \
    widgets/AnalysisList/dialogs/dialogprintpreview.cpp \
    widgets/AnalysisList/dialogs/dialogreceiptedit.cpp \
    widgets/AnalysisList/models/modelanalysislist.cpp \
    widgets/AnalysisList/widgetanalysislist.cpp \
    widgets/Ingredients/dialogs/dialogingredientedit.cpp \
    widgets/Ingredients/ingredient.cpp \
    widgets/Ingredients/models/modeltableingredient.cpp \
    widgets/Ingredients/widgetingredients.cpp

HEADERS += \
    database.h \
    mainwindow.h \
    widgets/AnalysisList/analysis.h \
    widgets/AnalysisList/dialogs/dialoganalysisedit.h \
    widgets/AnalysisList/dialogs/dialoganalysispreview.h \
    widgets/AnalysisList/dialogs/dialogprintpreview.h \
    widgets/AnalysisList/dialogs/dialogreceiptedit.h \
    widgets/AnalysisList/models/modelanalysislist.h \
    widgets/AnalysisList/widgetanalysislist.h \
    widgets/Ingredients/dialogs/dialogingredientedit.h \
    widgets/Ingredients/ingredient.h \
    widgets/Ingredients/models/modeltableingredient.h \
    widgets/Ingredients/widgetingredients.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
