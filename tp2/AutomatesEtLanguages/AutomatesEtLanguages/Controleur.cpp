#include "Controleur.h"

Controleur::Controleur()
{	
}

bool Controleur::InitialiserProgramme(std::string cheminFichier) const
{
	//lexique = UsineLexique::initialiserLexique(cheminFichier);
	return false;
}

std::string Controleur::VerifierOrthographeDuMot(std::string mot) const
{
	std::string motRetourne = mot;
	// Vérifier si le mot fait partit d'un des mots du lexique.
		// Si oui, retourne le mot. Celui-ci est bien orthographié.
	return motRetourne;

	// Si non, recherche parmi les mots commençant par la même lettre un mot qui s'apparente à celui-ci.

}


Controleur::~Controleur()
{
}
