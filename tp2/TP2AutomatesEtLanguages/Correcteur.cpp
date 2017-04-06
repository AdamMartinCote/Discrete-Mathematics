#include "Correcteur.h"



Correcteur::Correcteur()
{
}


Correcteur::~Correcteur()
{
}

std::string Correcteur::VerifierOrthographeDuMot(std::string mot, std::shared_ptr<Noeud> arbreDeLaLettre)
{
	std::vector<std::shared_ptr<Noeud>> motsPotentiels;
	std::string motRetourne = mot;
	int niveauMot = mot.size();

	// Vérifier si le mot fait partit d'un des mots du lexique.
	// Si oui, retourne le mot. Celui-ci est bien orthographié.
	if (arbreDeLaLettre->verifierSousChaine(mot))
		return motRetourne;

	// Si non, recherche parmi les mots commençant par la même lettre un mot qui s'apparente à celui-ci.
	else
	{
		// Recherche des mots potentiels de même niveau.
		motsPotentiels = arbreDeLaLettre->obtenirMotsSelonNiveau(niveauMot);

		// Filtrer et retourner le premier élément parmi ceux qui n'ont qu'un seul caractère différent.
		return (filtreNoeudsAvecUneSeuleDifference(motsPotentiels, mot) != nullptr) ? filtreNoeudsAvecUneSeuleDifference(motsPotentiels, mot)->obtenirValeur() : "Aucun mot trouvé dans le lexique.\n\n\n";
	}
	return "Aucun mot trouvé dans le lexique.\n\n\n";
}

std::shared_ptr<Noeud> Correcteur::filtreNoeudsAvecUneSeuleDifference(std::vector<std::shared_ptr<Noeud>> noeuds, std::string mot)
{
	std::vector<std::shared_ptr<Noeud>> noeudsAvecUneSeuleDifference;
	char carMotCourantDroite, carMotCourantGauche, carNoeudCourantDroite, carNoeudCourantGauche;
	int erreurNoeudCourant = 0;
	for (std::shared_ptr<Noeud> noeud : noeuds)
	{
		// i = position de droite, j = position de gauche.
		// La boucle sort s'il y a plus de deux erreurs.
		// OU si la position de droite dépasse la position de gauche.
		// OU si la position de guache et égale à la position de droite.
		for (int i = 0, j = mot.size() - 1; erreurNoeudCourant < 2 && i < j; i++, j--)
		{
			carMotCourantGauche = mot.at(i);
			carMotCourantDroite = mot.at(j);
			carNoeudCourantGauche = noeud->obtenirValeur().at(i);
			carNoeudCourantDroite = noeud->obtenirValeur().at(j);

			if (carMotCourantGauche != carNoeudCourantGauche)
				erreurNoeudCourant++;
			if (carMotCourantDroite != carNoeudCourantDroite && (i != j))	// Évite de compter deux fois l'erreur.
				erreurNoeudCourant++;
		}

		if (erreurNoeudCourant <= 1)
		{
			return noeud;
		}
		erreurNoeudCourant = 0;
	}

	return nullptr;
}
