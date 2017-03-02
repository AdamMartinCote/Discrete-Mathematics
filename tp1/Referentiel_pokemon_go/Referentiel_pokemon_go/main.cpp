#include <iostream>
#include <string>
#include <clocale>
#include <stdexcept>
#include "RPGController.h"

int main()
{
	setlocale(LC_ALL, "");	// affichage des charact�res fran�ais
	char input = 'z';
	std::string nodeName;
	unsigned int wantedGain;
	unsigned int maximumLength;


	// Creation du graphe unique � partir du txt
	RPGController rpgController;
	rpgController.creerGraphe("data\\data_pokemon.txt");

	while (input != 'd')
	{
		std::cout <<
			"(a) Mettre a jour la carte.\n"
			"(b) D�terminer le plus court chemin(et demander le gain minimal a obtenir)\n"
			"(c) D�terminer le plus grand gain(et demander la distance maximale a parcourir)\n"
			"(d) Quitter\n";

		std::cin >> input;

		switch (input)
		{
		case 'a':
			//rpgController.updateMap();
			rpgController.lireGraphe();
			break;
		case 'b':
			std::cout <<
				"Entrer le nom du noeud ou debuter:\n";
			std::cin >> nodeName;
			std::cout <<
				"Entrer le gain voulu:\n";
			std::cin >> wantedGain;

			std::cout << rpgController.plusCourtChemin(nodeName, wantedGain);
			break;
		case 'c':
			//rpgController.plusGrandGain();
			std::cout << 
				"Entrer le noeud où débuter:\n";
			std::cin >> nodeName;
			std::cout <<
				"Entrer la distance maximale à parcourir:\n";
			std::cin >> maximumLength;
			std::cout << rpgController.plusGrandGain(nodeName, maximumLength) << std::endl;
			break;
		default:
			break;

		}

	}
	return 0;
}