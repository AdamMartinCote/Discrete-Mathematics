#pragma once
#include <memory>
#include "Noeud.h"

class Lexique
{
public:
	Lexique();
	~Lexique();
	bool ajouterArbre(std::shared_ptr<Noeud> noeud);
	bool Lexique::ajouterNoeud(std::shared_ptr<Noeud> noeudAAjouter, char premierLettre);
	bool verifierSousChaine(std::string sousChaine);
	bool contientLettre(char lettre);
	std::shared_ptr<Noeud> Lexique::ObtenirArbre(char lettre);
private:
	std::vector<std::shared_ptr<Noeud>> lettresArbres_;
	bool Lexique::verifierSousChaine(std::string sousChaine, std::vector<std::shared_ptr<Noeud>> SousArbre);
	bool Lexique::ajouterNoeud(std::shared_ptr<Noeud> noeudAAjouter, std::vector<std::shared_ptr<Noeud>> sousArbre);
};

