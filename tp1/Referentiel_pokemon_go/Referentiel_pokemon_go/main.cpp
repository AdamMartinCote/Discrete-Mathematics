#include <iostream>
#include <clocale>
#include "RPGController.h"

int main()
{
	setlocale(LC_ALL, "");	// pour charact�res fran�ais
	RPGController rpgController;
	char input = 'z';

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
			rpgController.creerGraphe("data_pokemon.txt");
			break;
		case 'b':
			rpgController.plusCourtChemin();
			break;
		case 'c':
			rpgController.plusGrandGain();
			break;
		default:
			break;

		}

	}

}