#include <string>
#include "Lexique.h"
#include "GestionnaireSuggestions.h"
#include "UsineLexique.h"
#pragma once
class Controleur
{
public:
	Controleur();
	std::shared_ptr<Lexique> ObtenirLexique() const;
	bool InitialiserProgramme(std::string cheminFichier);
	void SuggestionDeMots(std::string motEntree) const;
	std::string VerifierOrthographeDuMot(std::string mot);
	~Controleur();

	static bool quitterProgramme;
private:
	std::shared_ptr<Lexique> lexique_;
};

