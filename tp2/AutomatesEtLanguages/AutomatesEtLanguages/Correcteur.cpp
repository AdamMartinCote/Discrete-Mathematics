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

	// V�rifier si le mot fait partit d'un des mots du lexique.
	// Si oui, retourne le mot. Celui-ci est bien orthographi�.
	if (arbreDeLaLettre->verifierSousChaine(mot))
		return motRetourne;

	// Si non, recherche parmi les mots commen�ant par la m�me lettre un mot qui s'apparente � celui-ci.
	else
	{
		// Recherche des mots potentiels de m�me niveau.
		motsPotentiels = arbreDeLaLettre->obtenirMotsSelonNiveau(niveauMot);

		// Filtrer et retourner le premier �l�ment parmi ceux qui n'ont qu'un seul caract�re diff�rent.
		return filtreNoeudsAvecUneSeuleDifference(motsPotentiels, mot).at(0)->obtenirValeur();
	}
	return "Aucun mot trouv� dans le lexique.\n\n\n";
}

std::vector<std::shared_ptr<Noeud>> Correcteur::filtreNoeudsAvecUneSeuleDifference(std::vector<std::shared_ptr<Noeud>> noeuds, std::string mot)
{
	std::vector<std::shared_ptr<Noeud>> noeudAvecUneSeuleDifference;
	char carMotCourantDroite, carMotCourantGauche, carNoeudCourantDroite, carNoeudCourantGauche;
	int erreurNoeudCourant = 0;
	for (std::shared_ptr<Noeud> noeud : noeuds)
	{
		// i = position de droite, j = position de gauche.
		// La boucle sort s'il y a plus de deux erreurs.
		// OU si la position de droite d�passe la position de gauche.
		// OU si la position de guache et �gale � la position de droite.
		for (int i = 0, j = mot.size() - 1; erreurNoeudCourant < 2 && i < j; i++, j--)
		{
			carMotCourantGauche = mot.at(i);
			carMotCourantDroite = mot.at(j);
			carNoeudCourantGauche = noeud->obtenirValeur().at(i);
			carNoeudCourantDroite = noeud->obtenirValeur().at(j);

			if (carMotCourantGauche != carNoeudCourantGauche)
				erreurNoeudCourant++;
			if (carMotCourantDroite != carNoeudCourantDroite && (i != j))	// �vite de compter deux fois l'erreur.
				erreurNoeudCourant++;
		}

		if (erreurNoeudCourant <= 1)
		{
			noeudAvecUneSeuleDifference.push_back(noeud);
		}
		erreurNoeudCourant = 0;
	}

	return noeudAvecUneSeuleDifference;
}
