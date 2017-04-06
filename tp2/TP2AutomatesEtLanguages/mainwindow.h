#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Controleur.h"
#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include <clocale>
#include "UsineLexique.h"

const int INDICE_LEXIQUE = 1;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_boutonQuitter_clicked();

    void on_actionSuggestion_triggered();

    void on_boutonSuggestion_clicked();

    void on_boutonRevenirMenu_clicked();

    void on_boutonOuvrir_clicked();

    void on_EntrerTextSuggestion_textChanged(const QString &arg1);

    void on_EntrerTextCorrection_returnPressed();

    void on_boutonCorrection_clicked();

    void on_boutonSuggestionCorrection_clicked();

    void on_EntrerTextSuggestionCorrection_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Controleur controleur;
};

#endif // MAINWINDOW_H
