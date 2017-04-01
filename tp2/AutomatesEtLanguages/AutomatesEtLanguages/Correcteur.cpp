#include "Correcteur.h"



Correcteur::Correcteur()
{
}


Correcteur::~Correcteur()
{
}

std::string Correcteur::VerifierOrthographeDuMot(std::string mot, std::shared_ptr<Noeud> arbreDeLaLettre)
{
	std::vector<std::shared_ptr<Noeud>> noeudsSimilaires;
	std::string motRetourne = mot;
	// V�rifier si le mot fait partit d'un des mots du lexique.
	// Si oui, retourne le mot. Celui-ci est bien orthographi�.
	if (arbreDeLaLettre->verifierSousChaine(mot))
		return motRetourne;

	// Si non, recherche parmi les mots commen�ant par la m�me lettre un mot qui s'apparente � celui-ci.
	else
	{
	}
	return "Aucun mot trouv� dans le lexique.\n\n\n";
}
