#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEntrerMot->setVisible(false);
    ui->EntrerTextSuggestion->setVisible(false);
    ui->EntrerTextCorrection->setVisible(false);
    ui->EntrerTextSuggestionCorrection->setVisible(false);
    ui->textOutput->setVisible(false);
    ui->boutonRevenirMenu->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_boutonQuitter_clicked()
{
    close();
}

void MainWindow::on_boutonOuvrir_clicked()
{
    //TODO : Initialiser un lexique
    QString filename=QFileDialog::getOpenFileName(
                this,
                tr("Choisir un lexique"),
                "C://",
                "Text File (*.txt);;All Files (*.*)");
    QString textbox="Le lexique "  + filename + " a bien été importé.";

    if(filename!= "")
        QMessageBox::information(this, tr("Lexique Importé"), textbox , tr("Ok"));
}

void MainWindow::on_actionSuggestion_triggered()
{
    //TODO : Initialiser un lexique
    QString filename=QFileDialog::getOpenFileName(
                this,
                tr("Choisir un lexique"),
                "C://",
                "Text File (*.txt);;All Files (*.*)");
    QString textbox="Le lexique "  + filename + " a bien été importé.";
    if(filename!="")
        QMessageBox::information(this, tr("Lexique Importé"), textbox , tr("Ok"));
}

void MainWindow::on_boutonSuggestion_clicked()
{
    //Cacher menu principal
    ui->boutonOuvrir->setVisible(false);
    ui->boutonSuggestion->setVisible(false);
    ui->boutonCorrection->setVisible(false);
    ui->boutonSuggestionCorrection->setVisible(false);
    ui->boutonQuitter->setVisible(false);

    //Montrer suggestion
    ui->textEntrerMot->setVisible(true);
    ui->EntrerTextSuggestion->setVisible(true);
    ui->textOutput->setVisible(true);
    ui->boutonRevenirMenu->setVisible(true);
}

void MainWindow::on_boutonCorrection_clicked()
{
    //Cacher menu principal
    ui->boutonOuvrir->setVisible(false);
    ui->boutonSuggestion->setVisible(false);
    ui->boutonCorrection->setVisible(false);
    ui->boutonSuggestionCorrection->setVisible(false);
    ui->boutonQuitter->setVisible(false);

    //Montrer correction
    ui->textEntrerMot->setVisible(true);
    ui->EntrerTextCorrection->setVisible(true);
    ui->textOutput->setVisible(true);
    ui->boutonRevenirMenu->setVisible(true);
}

void MainWindow::on_boutonSuggestionCorrection_clicked()
{
    //Cacher menu principal
    ui->boutonOuvrir->setVisible(false);
    ui->boutonSuggestion->setVisible(false);
    ui->boutonCorrection->setVisible(false);
    ui->boutonSuggestionCorrection->setVisible(false);
    ui->boutonQuitter->setVisible(false);

    //Montrer suggestion-correction
    ui->textEntrerMot->setVisible(true);
    ui->EntrerTextSuggestionCorrection->setVisible(true);
    ui->textOutput->setVisible(true);
    ui->boutonRevenirMenu->setVisible(true);
}

void MainWindow::on_boutonRevenirMenu_clicked()
{
    //Montrer menu principal
    ui->boutonOuvrir->setVisible(true);
    ui->boutonSuggestion->setVisible(true);
    ui->boutonCorrection->setVisible(true);
    ui->boutonSuggestionCorrection->setVisible(true);
    ui->boutonQuitter->setVisible(true);

    //Cacher les bouton hors menu principal
    ui->textEntrerMot->setVisible(false);
    ui->EntrerTextSuggestion->setVisible(false);
    ui->EntrerTextCorrection->setVisible(false);
    ui->EntrerTextSuggestionCorrection->setVisible(false);
    ui->textOutput->setVisible(false);
    ui->boutonRevenirMenu->setVisible(false);
}



void MainWindow::on_EntrerTextSuggestion_textChanged(const QString &arg1)
{
    //TODO : Utiliser fonction suggestion
    QMessageBox::information(this, tr("test"), tr("suggestion") , tr("Ok")); //Test pour vérifier si l'event fonctionne
}

void MainWindow::on_EntrerTextCorrection_returnPressed()
{
    //TODO : Utiliser fonction correction
    QMessageBox::information(this, tr("test"), tr("correction") , tr("Ok")); //Test pour vérifier si l'event fonctionne
}

void MainWindow::on_EntrerTextSuggestionCorrection_textChanged(const QString &arg1)
{
    //TODO : Utiliser fonction suggestion
    QMessageBox::information(this, tr("test"), tr("suggestion") , tr("Ok")); //Test pour vérifier si l'event fonctionne
}
