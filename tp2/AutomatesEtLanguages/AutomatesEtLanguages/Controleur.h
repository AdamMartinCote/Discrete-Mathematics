#include <string>
#include "Lexique.h"
#pragma once
class Controleur
{
public:
	Controleur();
	bool InitialiserProgramme(std::string cheminFichier) const;
	std::string VerifierOrthographeDuMot(std::string mot) const;
	~Controleur();
private:
	Lexique lexique;
};

