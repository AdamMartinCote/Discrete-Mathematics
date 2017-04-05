/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuitter;
    QAction *actionSuggestion;
    QWidget *centralWidget;
    QPushButton *boutonOuvrir;
    QPushButton *boutonSuggestion;
    QPushButton *boutonCorrection;
    QPushButton *boutonSuggestionCorrection;
    QPushButton *boutonQuitter;
    QLineEdit *EntrerTextSuggestion;
    QTextBrowser *textTitreMain;
    QTextBrowser *textPar;
    QTextBrowser *textOutput;
    QPushButton *boutonRevenirMenu;
    QTextBrowser *textEntrerMot;
    QLineEdit *EntrerTextCorrection;
    QLineEdit *EntrerTextSuggestionCorrection;
    QTextBrowser *textTitreSuggestion;
    QTextBrowser *textTitreCorrection;
    QTextBrowser *textTitreSuggestionCorrection;
    QMenuBar *menuBar;
    QMenu *accueil;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(478, 513);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        actionSuggestion = new QAction(MainWindow);
        actionSuggestion->setObjectName(QStringLiteral("actionSuggestion"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        boutonOuvrir = new QPushButton(centralWidget);
        boutonOuvrir->setObjectName(QStringLiteral("boutonOuvrir"));
        boutonOuvrir->setGeometry(QRect(70, 100, 341, 41));
        boutonSuggestion = new QPushButton(centralWidget);
        boutonSuggestion->setObjectName(QStringLiteral("boutonSuggestion"));
        boutonSuggestion->setGeometry(QRect(70, 160, 341, 41));
        boutonCorrection = new QPushButton(centralWidget);
        boutonCorrection->setObjectName(QStringLiteral("boutonCorrection"));
        boutonCorrection->setGeometry(QRect(70, 220, 341, 41));
        boutonSuggestionCorrection = new QPushButton(centralWidget);
        boutonSuggestionCorrection->setObjectName(QStringLiteral("boutonSuggestionCorrection"));
        boutonSuggestionCorrection->setGeometry(QRect(70, 280, 341, 41));
        boutonQuitter = new QPushButton(centralWidget);
        boutonQuitter->setObjectName(QStringLiteral("boutonQuitter"));
        boutonQuitter->setGeometry(QRect(70, 340, 341, 41));
        EntrerTextSuggestion = new QLineEdit(centralWidget);
        EntrerTextSuggestion->setObjectName(QStringLiteral("EntrerTextSuggestion"));
        EntrerTextSuggestion->setGeometry(QRect(20, 140, 441, 22));
        textTitreMain = new QTextBrowser(centralWidget);
        textTitreMain->setObjectName(QStringLiteral("textTitreMain"));
        textTitreMain->setGeometry(QRect(40, 30, 401, 51));
        textPar = new QTextBrowser(centralWidget);
        textPar->setObjectName(QStringLiteral("textPar"));
        textPar->setGeometry(QRect(100, 420, 281, 41));
        textOutput = new QTextBrowser(centralWidget);
        textOutput->setObjectName(QStringLiteral("textOutput"));
        textOutput->setGeometry(QRect(20, 170, 441, 191));
        boutonRevenirMenu = new QPushButton(centralWidget);
        boutonRevenirMenu->setObjectName(QStringLiteral("boutonRevenirMenu"));
        boutonRevenirMenu->setGeometry(QRect(70, 370, 341, 41));
        textEntrerMot = new QTextBrowser(centralWidget);
        textEntrerMot->setObjectName(QStringLiteral("textEntrerMot"));
        textEntrerMot->setGeometry(QRect(20, 100, 151, 31));
        EntrerTextCorrection = new QLineEdit(centralWidget);
        EntrerTextCorrection->setObjectName(QStringLiteral("EntrerTextCorrection"));
        EntrerTextCorrection->setGeometry(QRect(20, 140, 441, 22));
        EntrerTextSuggestionCorrection = new QLineEdit(centralWidget);
        EntrerTextSuggestionCorrection->setObjectName(QStringLiteral("EntrerTextSuggestionCorrection"));
        EntrerTextSuggestionCorrection->setGeometry(QRect(20, 140, 441, 22));
        textTitreSuggestion = new QTextBrowser(centralWidget);
        textTitreSuggestion->setObjectName(QStringLiteral("textTitreSuggestion"));
        textTitreSuggestion->setGeometry(QRect(40, 30, 401, 51));
        textTitreCorrection = new QTextBrowser(centralWidget);
        textTitreCorrection->setObjectName(QStringLiteral("textTitreCorrection"));
        textTitreCorrection->setGeometry(QRect(40, 30, 401, 51));
        textTitreSuggestionCorrection = new QTextBrowser(centralWidget);
        textTitreSuggestionCorrection->setObjectName(QStringLiteral("textTitreSuggestionCorrection"));
        textTitreSuggestionCorrection->setGeometry(QRect(40, 30, 401, 51));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 478, 19));
        accueil = new QMenu(menuBar);
        accueil->setObjectName(QStringLiteral("accueil"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(accueil->menuAction());
        accueil->addAction(actionSuggestion);
        accueil->addSeparator();
        accueil->addAction(actionQuitter);

        retranslateUi(MainWindow);
        QObject::connect(actionQuitter, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
        actionSuggestion->setText(QApplication::translate("MainWindow", "Choisir Lexique", Q_NULLPTR));
        boutonOuvrir->setText(QApplication::translate("MainWindow", "Ouvrir un lexique", Q_NULLPTR));
        boutonSuggestion->setText(QApplication::translate("MainWindow", "Utiliser la fonctionnalit\303\251 de suggestion", Q_NULLPTR));
        boutonCorrection->setText(QApplication::translate("MainWindow", "Utiliser la fonctionnalit\303\251 de correction", Q_NULLPTR));
        boutonSuggestionCorrection->setText(QApplication::translate("MainWindow", "Utiliser la fonctionnalit\303\251 de suggestion et de correction", Q_NULLPTR));
        boutonQuitter->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
        textTitreMain->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:22pt;\">Automates et Langages</span></p></body></html>", Q_NULLPTR));
        textPar->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; color:#0000ff;\">Team Artifices</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; color:#0000ff;\">Jonathan, Adam et Louis</span></p></body></html>", Q_NULLPTR));
        textOutput->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        boutonRevenirMenu->setText(QApplication::translate("MainWindow", "Revenir au menu principal", Q_NULLPTR));
        textEntrerMot->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">Entrez un mot :</span></p></body></html>", Q_NULLPTR));
        textTitreSuggestion->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:22pt;\">Suggestion</span></p></body></html>", Q_NULLPTR));
        textTitreCorrection->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:22pt;\">Correction</span></p></body></html>", Q_NULLPTR));
        textTitreSuggestionCorrection->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:22pt;\">Suggestion et Correction</span></p></body></html>", Q_NULLPTR));
        accueil->setTitle(QApplication::translate("MainWindow", "Accueil", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
