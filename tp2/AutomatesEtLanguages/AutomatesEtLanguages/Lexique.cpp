#include "Lexique.h"



Lexique::Lexique()
{
}


Lexique::~Lexique()
{
}

bool Lexique::ajouterArbre(std::shared_ptr<Noeud> noeud)
{
	if (noeud->obtenirParent() != nullptr)
		return false;

	lettresArbres_.push_back(noeud);
	return true;
}

bool Lexique::ajouterNoeud(std::shared_ptr<Noeud> noeudAAjouter, char premierLettre)
{
	if (contientLettre(premierLettre))
	{
		return true;
	}
	return false;
}

bool Lexique::verifierSousChaine(std::string sousChaine)
{
	for (std::shared_ptr<Noeud> lettreArbre : lettresArbres_)
	{
		if (lettreArbre->obtenirValeur() == sousChaine)
			return true;
		else
			verifierSousChaine(sousChaine, lettreArbre->obtenirEnfants());			
	}
	return false;
}

bool Lexique::verifierSousChaine(std::string sousChaine, std::vector<std::shared_ptr<Noeud>> SousArbre)
{
	for (std::shared_ptr<Noeud> noeudParent : SousArbre)
	{
		if (noeudParent->obtenirValeur() == sousChaine)
			return true;
		else
			verifierSousChaine(sousChaine, noeudParent->obtenirEnfants());
	}
}

bool Lexique::contientLettre(char lettre)
{
	std::string lettreAChercher(1, lettre);
	for (std::shared_ptr<Noeud> arbre : lettresArbres_)
	{
		if (arbre->obtenirValeur() == lettreAChercher)
			return true;
	}
	return false;
}

std::shared_ptr<Noeud> Lexique::ObtenirArbre(char lettre)
{
	std::string lettreAChercher(1, lettre);

	for (std::shared_ptr<Noeud> arbre : lettresArbres_)
	{
		if (arbre->obtenirValeur() == lettreAChercher)
			return arbre;
	}

	return nullptr;
}
