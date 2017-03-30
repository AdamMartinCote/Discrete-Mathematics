#include "UsineLexique.h"

#include <iostream>



UsineLexique::UsineLexique()
{
}


UsineLexique::~UsineLexique()
{
}

Lexique UsineLexique::initialiserLexique(std::string nomFichier)
{
	std::ifstream fichier;
	fichier.open(nomFichier);
	if (!fichier.is_open()) throw new std::exception("file couldn't not be opened");
	else std::cout << "file opened" << std::endl;

	std::string buffer;
	std::unique_ptr<Lexique> init;
	while (std::getline(fichier, buffer)) {
		for (auto caractere : buffer) {

		}
	}

	return Lexique();
}
