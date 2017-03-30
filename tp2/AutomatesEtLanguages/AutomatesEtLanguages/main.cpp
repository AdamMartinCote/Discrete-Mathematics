#include <iostream>
#include <clocale>
#include "Controleur.h"
#include "UsineLexique.h"

void MenuPrincipal(Controleur* controleur);
void AfficherMenu();
void ExecuterChoix(char choixUtilisateur, Controleur* controleur);
void RetourAuMenu(Controleur* controleur);


const int INDICE_LEXIQUE = 1;
int main() {
	setlocale(LC_ALL, "");
	Controleur controleur;

	try {
		MenuPrincipal(&controleur);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}

void MenuPrincipal(Controleur* controleur)
{
	char choixUtilisateur;
	AfficherMenu();
	std::cin >> choixUtilisateur;
	ExecuterChoix(choixUtilisateur, controleur);
}

void AfficherMenu()
{
	std::cout << "TP2: Automates et langages" << "\n";
	std::cout << "Par : Jonathan, Adam et Louis" << "\n";
	std::cout << "\n\n" << "Veuillez choisir parmi les options suivantes :" << "\n";
	std::cout << "1) Initialiser le programme." << "\n";
	std::cout << "2) Utiliser la fonctionnalité de suggestion." << "\n";
	std::cout << "3) Utiliser la fonctionnalité de correction." << "\n";
	std::cout << "4) Utiliser la fonctionnalité de suggestion et de correction." << "\n";
	std::cout << "5) Quitter le programme." << "\n";
}

void ExecuterChoix(char choixUtilisateur, Controleur* controleur) 
{
	std::string motUtilisateur, motCorrige;

	switch (choixUtilisateur)
	{
	case '1':
		controleur->InitialiserProgramme("donnee/lexique" + std::to_string(INDICE_LEXIQUE) + ".txt");
		break;
	case '2':
		RetourAuMenu(controleur);
		break;
	case '3':
		std::cout << "Veuillez entrer un mot:";
		std::cin >> motUtilisateur;
		motCorrige = controleur->VerifierOrthographeDuMot(motUtilisateur);
		std::cout << "Voici le mot corrigé : " << "\n";
		std::cout << motCorrige << "\n";

		RetourAuMenu(controleur);
		
		break;
	case '4':
		RetourAuMenu(controleur);
		break;
	case '5':
		std::cout << "Merci d'avoir utiliser notre application..." << "\n";
		system("pause");
		break;
	}
}

void RetourAuMenu(Controleur* controleur)
{
	char choixUtilisateur;
	std::cout << "Voulez-vous retourner au menu principal ? (oui/non)" << "\n";
	std::cin >> choixUtilisateur;
	if (choixUtilisateur == 'o')
	{ 
		MenuPrincipal(controleur);
	}
}