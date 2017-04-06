#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setlocale(LC_ALL, "");

    ui->setupUi(this);
    ui->textEntrerMot->setVisible(false);
    ui->EntrerTextSuggestion->setVisible(false);
    ui->EntrerTextCorrection->setVisible(false);
    ui->EntrerTextSuggestionCorrection->setVisible(false);
    ui->textOutput->setVisible(false);
    ui->boutonRevenirMenu->setVisible(false);
    ui->textTitreSuggestion->setVisible(false);
    ui->textTitreCorrection->setVisible(false);
    ui->textTitreSuggestionCorrection->setVisible(false);
    ui->textEntrerMot_2->setVisible(false);
    ui->boutonSuggestion->setVisible(false);
    ui->boutonCorrection->setVisible(false);
    ui->boutonSuggestionCorrection->setVisible(false);
    ui->boutonQuitter->setVisible(false);
    ui->textTitreMain->setVisible(false);
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
    QString nomDuFichier=QFileDialog::getOpenFileName(
                this,
                tr("Choisir un lexique"),
                "C://",
                "Text File (*.txt);;All Files (*.*)");

    std::string nomDuFichierConverti = nomDuFichier.toUtf8().constData();
    std::replace( nomDuFichierConverti.begin(), nomDuFichierConverti.end(), '\\', '/');
    QString message = "Le lexique " + QString::fromStdString(nomDuFichierConverti);
    if (nomDuFichierConverti != ""){
        QMessageBox::information(this, tr("Importation en cours..."), message + " est en cours d'exportation..." , tr("Ok"));
        controleur.InitialiserProgramme(nomDuFichierConverti);

        if(nomDuFichierConverti!= "")
        QMessageBox::information(this, tr("Lexique Importé"), message + "est importé." , tr("Ok"));
        ui->boutonSuggestion->setVisible(true);
        ui->boutonCorrection->setVisible(true);
        ui->boutonSuggestionCorrection->setVisible(true);
        ui->boutonQuitter->setVisible(true);
        ui->textTitreMain->setVisible(true);
    }
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
    ui->textTitreMain->setVisible(false);

    //Montrer suggestion
    ui->textEntrerMot->setVisible(true);
    ui->EntrerTextSuggestion->setVisible(true);
    ui->textOutput->setVisible(true);
    ui->boutonRevenirMenu->setVisible(true);
    ui->textTitreSuggestion->setVisible(true);
}

void MainWindow::on_boutonCorrection_clicked()
{
    //Cacher menu principal
    ui->boutonOuvrir->setVisible(false);
    ui->boutonSuggestion->setVisible(false);
    ui->boutonCorrection->setVisible(false);
    ui->boutonSuggestionCorrection->setVisible(false);
    ui->boutonQuitter->setVisible(false);
    ui->textTitreMain->setVisible(false);

    //Montrer correction
    ui->EntrerTextCorrection->setVisible(true);
    ui->textOutput->setVisible(true);
    ui->boutonRevenirMenu->setVisible(true);
    ui->textTitreCorrection->setVisible(true);
    ui->textEntrerMot_2->setVisible(true);
}

void MainWindow::on_boutonSuggestionCorrection_clicked()
{
    //Cacher menu principal
    ui->boutonOuvrir->setVisible(false);
    ui->boutonSuggestion->setVisible(false);
    ui->boutonCorrection->setVisible(false);
    ui->boutonSuggestionCorrection->setVisible(false);
    ui->boutonQuitter->setVisible(false);
    ui->textTitreMain->setVisible(false);

    //Montrer suggestion-correction
    ui->textEntrerMot_2->setVisible(true);
    ui->EntrerTextSuggestionCorrection->setVisible(true);
    ui->textOutput->setVisible(true);
    ui->boutonRevenirMenu->setVisible(true);
    ui->textTitreSuggestionCorrection->setVisible(true);
}

void MainWindow::on_boutonRevenirMenu_clicked()
{
    //Montrer menu principal
    ui->boutonOuvrir->setVisible(true);
    ui->boutonSuggestion->setVisible(true);
    ui->boutonCorrection->setVisible(true);
    ui->boutonSuggestionCorrection->setVisible(true);
    ui->boutonQuitter->setVisible(true);
    ui->textTitreMain->setVisible(true);

    //Cacher les bouton hors menu principal
    ui->textEntrerMot->setVisible(false);
    ui->EntrerTextSuggestion->setVisible(false);
    ui->EntrerTextCorrection->setVisible(false);
    ui->EntrerTextSuggestionCorrection->setVisible(false);
    ui->textOutput->setVisible(false);
    ui->boutonRevenirMenu->setVisible(false);
    ui->textTitreSuggestion->setVisible(false);
    ui->textTitreCorrection->setVisible(false);
    ui->textTitreSuggestionCorrection->setVisible(false);
    ui->textEntrerMot_2->setVisible(false);

    //Vider les zones de text
    ui->EntrerTextSuggestion->clear();
    ui->EntrerTextCorrection->clear();
    ui->EntrerTextSuggestionCorrection->clear();
    ui->textOutput->clear();
}



void MainWindow::on_EntrerTextSuggestion_textChanged(const QString &arg1)
{
    if(arg1 != NULL && arg1 != "")
    {
        // suggestion
        ui->textOutput->setText(VerifierSuggererTexteEntree(arg1));
    }
}

void MainWindow::on_EntrerTextCorrection_textChanged(const QString &arg1)
{
    if(arg1 != NULL && arg1 != "")
    {
        std::string textCorrige = AjusterEtVerifierTexteEntree(arg1);
        if(textCorrige != "")
            ui->EntrerTextCorrection->setText(QString::fromStdString(textCorrige));
    }
}

void MainWindow::on_EntrerTextSuggestionCorrection_textChanged(const QString &arg1)
{
    if(arg1 != NULL && arg1 != "")
    {
        // suggestion
        ui->textOutput->setText(VerifierSuggererTexteEntree(arg1));

        // correction
        std::string textCorrige = AjusterEtVerifierTexteEntree(arg1);
        if(textCorrige != "")
            ui->EntrerTextSuggestionCorrection->setText(QString::fromStdString(textCorrige));
    }
}

std::string MainWindow::AjusterEtVerifierTexteEntree(const QString &texteUtilisateur)
{
    std::string entre = texteUtilisateur.toUtf8().constData();
    std::string debutChain = "";

    if(entre.at(entre.size()-1) == ' ')
    {
        entre.pop_back();

        // On s'assure que l'on évalue un seul mot et non plusieurs.
        if (entre.find(" ") != std::string::npos) {
            std::size_t derniereEspace = entre.find_last_of(' ');
            debutChain = entre.substr(0, derniereEspace) + ' ';
            entre = entre.substr(derniereEspace+1);
        }

        return debutChain + controleur.VerifierOrthographeDuMot(entre) + " ";
    }
    return "";
}

QString MainWindow::VerifierSuggererTexteEntree(const QString &texteUtilisateur)
{
    std::string entreeUtilisateur = texteUtilisateur.toUtf8().constData();
    // suggestion
    if (entreeUtilisateur.find(" ") != std::string::npos) {
        std::size_t derniereEspace = entreeUtilisateur.find_last_of(' ');
        entreeUtilisateur = entreeUtilisateur.substr(derniereEspace+1);
    }
    QString texteAEvaluer = QString::fromStdString(controleur.SuggestionDeMots(entreeUtilisateur));
    return (texteAEvaluer == "" || texteAEvaluer == NULL) ? " " : texteAEvaluer;
}
