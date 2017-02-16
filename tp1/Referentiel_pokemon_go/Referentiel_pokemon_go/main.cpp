#include <iostream>
#include "RPGController.h"

int main()
{

	RPGController rpgController;
	char input = 'z';

	while(input != 'd')
	{
		std::cout <<
			"(a)Mettre a jour la carte.\n"
			"(b)Determiner le plus court chemin(et demander le gain minimal a obtenir)\n"
			"(c) Determiner le plus grand gain(et demander la distance maximale a parcourir)\n"
			"(d) Quitter\n";

		std::cin >> input;

		switch(input)
		{
		case 'a':
			rpgController.updateMap();
			break;
		case 'b':
			rpgController.getShortestPath();
			break;
		case 'c':
			rpgController.getLargestGain();
			break;
		default:
			break;

		}

	}

}
