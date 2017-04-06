#include <string>
#include "Lexique.h"
#include "GestionnaireSuggestions.h"
#include "Correcteur.h"
#include "UsineLexique.h"
#pragma once
class Controleur
{
public:
	Controleur();
	std::shared_ptr<Lexique> ObtenirLexique() const;
	bool InitialiserProgramme(std::string cheminFichier);
	std::string SuggestionDeMots(std::string motEntree) const;
	std::string VerifierOrthographeDuMot(std::string mot);
	std::string SuggestionCorrection(std::string motEntree) const;
	~Controleur();

	static bool quitterProgramme;
private:
	std::shared_ptr<Lexique> lexique_;
};

