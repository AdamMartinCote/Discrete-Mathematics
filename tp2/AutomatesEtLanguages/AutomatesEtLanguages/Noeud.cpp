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
	return 0;
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

void Noeud::AfficherPremierMotDuSousArbre() const
{
	const Noeud * tmp = this;
	while(!tmp->estUnMot()){
		tmp = (tmp->enfants_[0]).get();
	}
	std::cout << tmp->valeur_ << std::endl;
}

void Noeud::marquerUnMot()
{
	estUnMot_ = true;
}

void Noeud::ajouterEnfant(std::shared_ptr<Noeud> noeudAAjouter)
{
	enfants_.push_back(noeudAAjouter);
}

int Noeud::obtenirNombreEnfants() const {
	return enfants_.size();
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

