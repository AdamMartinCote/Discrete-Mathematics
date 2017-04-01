#include <iostream>
#include "Noeud.h"



Noeud::Noeud(std::string valeur, bool estUnMot, unsigned int niveau, std::shared_ptr<Noeud> parent)
	:valeur_(valeur), estUnMot_(estUnMot), niveau_(niveau), parent_(parent)
{
}

Noeud::Noeud(std::string valeur, bool estUnMot, unsigned int niveau)
	: valeur_(valeur), estUnMot_(estUnMot), niveau_(niveau)
{
}

Noeud::~Noeud()
{
}

std::vector<std::shared_ptr<Noeud>> Noeud::obtenirEnfants() const
{
	return enfants_;
}

std::shared_ptr<Noeud> Noeud::obtenirParent() const
{
	return parent_;
}

bool Noeud::estUnMot() const
{
	return estUnMot_;
}

unsigned int Noeud::obtenirNiveau() const
{
	return niveau_;
}

std::string Noeud::obtenirValeur() const
{
	return valeur_;
}

bool Noeud::trouverChaineDansSousArbre(std::string) const
{
	return false;
}

void Noeud::AfficherEnfants() const
{
	for (auto i : enfants_) {
		std::cout << i->valeur_ << " ";
	}
	std::cout << std::endl;
}

void Noeud::ajouterEnfant(std::shared_ptr<Noeud> noeudAAjouter)
{
	enfants_.push_back(noeudAAjouter);
}

int Noeud::obtenirNombreEnfants() const {
	return enfants_.size();
}

std::vector<std::shared_ptr<Noeud>> Noeud::obtenirMotsSelonNiveau(int niveau)
{
	std::vector<std::shared_ptr<Noeud>> noeudsTrouves;
	auto ptrNoeudsTrouvesPartages = std::make_shared<std::vector<std::shared_ptr<Noeud>>>(noeudsTrouves);

	if (niveau == niveau_)
		noeudsTrouves.push_back(std::shared_ptr<Noeud>(this));
	obtenirMotSelonNiveau(niveau, ptrNoeudsTrouvesPartages);
	return *ptrNoeudsTrouvesPartages.get();
}

void Noeud::obtenirMotSelonNiveau(int niveau, std::shared_ptr<std::vector<std::shared_ptr<Noeud>>> noeudsTrouves)
{
	for (std::shared_ptr<Noeud> enfant : enfants_)
	{
		if (enfant->estUnMot() && niveau == enfant->obtenirNiveau())
			noeudsTrouves->push_back(enfant);
		else
			enfant->obtenirMotSelonNiveau(niveau, noeudsTrouves);
	}
}

bool Noeud::verifierSousChaine(std::string sousChaine)
{
	return verifierSousChaine(sousChaine, obtenirEnfants());
}

bool Noeud::verifierSousChaine(std::string sousChaine, std::vector<std::shared_ptr<Noeud>> SousArbre)
{
	for (std::shared_ptr<Noeud> noeudParent : SousArbre)
	{
		if (noeudParent->obtenirValeur() != sousChaine)
			return verifierSousChaine(sousChaine, noeudParent->obtenirEnfants());
		else
		{
			if ((noeudParent->obtenirValeur() == sousChaine) && (noeudParent->estUnMot()))
				return true;
			else
				return false;
		}
	}
	return false;
}

