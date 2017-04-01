#pragma once
#include <memory>
#include "Noeud.h"

class Lexique
{
public:
	Lexique();
	~Lexique();

	std::vector<std::shared_ptr<Noeud>> ObtenirLettresArbres();

	bool ajouterArbre(std::shared_ptr<Noeud> noeud);
	bool Lexique::ajouterNoeud(std::shared_ptr<Noeud> noeudAAjouter, char premierLettre);
	bool contientLettre(char lettre);
	std::shared_ptr<Noeud> Lexique::ObtenirArbreDeLaLettre(char lettre);

	std::vector<std::shared_ptr<Noeud>> obtenirLesArbres() const;

private:
	std::vector<std::shared_ptr<Noeud>> lettresArbres_;
	bool Lexique::ajouterNoeud(std::shared_ptr<Noeud> noeudAAjouter, std::vector<std::shared_ptr<Noeud>> sousArbre);

	friend class UsineLexique;
};

