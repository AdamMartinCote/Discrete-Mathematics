#include <iostream>
#include <clocale>
#include "Controleur.h"
#include "UsineLexique.h"

const int INDICE_LEXIQUE = 1;

// prototypes
void MenuPrincipal(Controleur* controleur);
void AfficherMenu();
void ExecuterChoix(char choixUtilisateur, Controleur* controleur);
void ChoixRetourAuMenu(Controleur* controleur, char choixUtilisateur);

int main() {
	setlocale(LC_ALL, "");
	Controleur controleur;

	while (!controleur.quitterProgramme) {
		MenuPrincipal(&controleur);
	}
	return 0;
}

void MenuPrincipal(Controleur* controleur)
{
	AfficherMenu();
	char choixUtilisateur;
	std::cin >> choixUtilisateur;
	ExecuterChoix(choixUtilisateur, controleur);
}

void AfficherMenu()
{
	std::cout << "\nTP2: Automates et langages" << "\n";
	std::cout << "Par : Jonathan, Adam et Louis" << "\n";
	std::cout << "\n" << "Veuillez choisir parmi les options suivantes :" << "\n";
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
		try {
			controleur->InitialiserProgramme("donnee/lexique" + std::to_string(INDICE_LEXIQUE) + ".txt");
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		catch (...) {
			std::cout << "une erreur inconnue est survenue" << std::endl;
		}
		break;
	case '2':
		//ChoixRetourAuMenu(controleur, choixUtilisateur);
		break;
	case '3':
		std::cout << "Veuillez entrer un mot:";
		std::cin >> motUtilisateur;
		motCorrige = controleur->VerifierOrthographeDuMot(motUtilisateur);
		std::cout << "Voici le mot corrigé : " << "\n";
		std::cout << motCorrige << "\n";

		//ChoixRetourAuMenu(controleur, choixUtilisateur);
		
		break;
	case '4':
		//ChoixRetourAuMenu(controleur, choixUtilisateur);
		break;
	case '5':
		std::cout << "Merci d'avoir utiliser notre application..." << "\n";
		controleur->quitterProgramme = true;
		//system("pause");
		std::cin.get();	// portabilité linux
		break;
	}
}

void ChoixRetourAuMenu(Controleur* controleur, char etatCourant)
{
	char choixUtilisateur;
	std::cout << "Voulez-vous retourner au menu principal ? (oui/non)" << "\n";
	std::cin >> choixUtilisateur;
	if (choixUtilisateur == 'o')
	{
		MenuPrincipal(controleur);
	}
	else
		ExecuterChoix(etatCourant, controleur);
}