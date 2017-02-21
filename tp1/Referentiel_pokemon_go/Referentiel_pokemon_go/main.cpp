#include <iostream>
#include <clocale>
#include "RPGController.h"

int main()
{
	setlocale(LC_ALL, "");	// affichage des charactères français
	char input = 'z';


	// Creation du graphe unique à partir du txt
	RPGController rpgController;
	rpgController.creerGraphe("data\\data_pokemon.txt");

	while (input != 'd')
	{
		std::cout <<
			"(a) Mettre a jour la carte.\n"
			"(b) Déterminer le plus court chemin(et demander le gain minimal a obtenir)\n"
			"(c) Déterminer le plus grand gain(et demander la distance maximale a parcourir)\n"
			"(d) Quitter\n";

		std::cin >> input;

		switch (input)
		{
		case 'a':
			//rpgController.updateMap();
			rpgController.lireGraphe();
			break;
		case 'b':
			//rpgController.plusCourtChemin();
			break;
		case 'c':
			//rpgController.plusGrandGain();
			break;
		default:
			break;

		}

	}

}