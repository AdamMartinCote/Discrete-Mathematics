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
	// Vérifier si le mot fait partit d'un des mots du lexique.
	// Si oui, retourne le mot. Celui-ci est bien orthographié.
	if (arbreDeLaLettre->verifierSousChaine(mot))
		return motRetourne;

	// Si non, recherche parmi les mots commençant par la même lettre un mot qui s'apparente à celui-ci.
	else
	{
	}
	return "Aucun mot trouvé dans le lexique.\n\n\n";
}
