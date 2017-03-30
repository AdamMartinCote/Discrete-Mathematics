#include <string>
#include "Lexique.h"
#pragma once
class Controleur
{
public:
	Controleur();
	bool InitialiserProgramme(std::string cheminFichier);
	std::string VerifierOrthographeDuMot(std::string mot);
	~Controleur();
private:
	Lexique lexique_;
};

