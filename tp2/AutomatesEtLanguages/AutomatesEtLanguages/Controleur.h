#include <string>
#include "Lexique.h"
#include "UsineLexique.h"
#pragma once
class Controleur
{
public:
	Controleur();
	bool InitialiserProgramme(std::string cheminFichier);
	std::string VerifierOrthographeDuMot(std::string mot);
	~Controleur();
private:
	std::unique_ptr<Lexique> lexique_;
};

