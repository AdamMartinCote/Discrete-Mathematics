#include <iostream>
#include <clocale>

#include "UsineLexique.h"

const int INDICE_LEXIQUE = 1;
int main() {
	setlocale(LC_ALL, "");
	char choixUtilisateur;
	Lexique lexique;

	try {

		std::cout << "TP2: Automates et langages" << "\n";
		std::cout << "Par : Jonathan, Adam et Louis" << "\n";
		std::cout << "\n\n" << "Veuillez choisir parmi les options suivantes :" << "\n";
		std::cout << "1) Initialiser le programme." << "\n";
		std::cout << "2) Utiliser la fonctionnalité de suggestion." << "\n";
		std::cout << "3) Utiliser la fonctionnalité de correction." << "\n";
		std::cout << "4) Utiliser la fonctionnalité de suggestion et de correction." << "\n";
		std::cout << "5) Quitter le programme." << "\n";

		std::cin >> choixUtilisateur;

		switch (choixUtilisateur)
		{
		case '1':
			lexique = UsineLexique::initialiserLexique("donnee/lexique" + std::to_string(INDICE_LEXIQUE) + ".txt");
			break;
		case '2':
			break;
		case '3':
			break;
		case '4':
			break;
		case '5':
			std::cout << "Merci d'avoir utiliser notre application..." << "\n";
			system("pause");
			break;
		}
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}