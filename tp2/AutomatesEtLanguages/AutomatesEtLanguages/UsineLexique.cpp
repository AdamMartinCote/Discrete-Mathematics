#include "UsineLexique.h"

#include <iostream>
#include <vector>



UsineLexique::UsineLexique()
{
}


UsineLexique::~UsineLexique()
{
}

std::unique_ptr<Lexique> UsineLexique::initialiserLexique(std::string nomFichier)
{
	std::ifstream fichier;
	fichier.open(nomFichier);
	if (!fichier.is_open()) throw std::runtime_error("Le fichier n'a pu être ouvert, vérifier le chemin d'accès.");

	// creer un arbre de toute les sous-chaines, sans optimisation (avec doublons)
	std::string buffer, sousChaine;
	std::unique_ptr<Lexique> lexique(new Lexique());
	while (std::getline(fichier, buffer)) {

		auto nouveauNoeud = std::make_shared<Noeud>(buffer.substr(0, 1), false, 1);	//premiere lettre
		auto dernierNoeud = nouveauNoeud;
		lexique->lettresArbres_.push_back(nouveauNoeud);

		unsigned int longueurSousChaine = 2;
		while (longueurSousChaine <= buffer.length()) {	// generer les sous-chaines et les chainer
			sousChaine = buffer.substr(0, longueurSousChaine);
			nouveauNoeud = std::make_shared<Noeud>(sousChaine, false, longueurSousChaine);
			dernierNoeud->ajouterEnfant(nouveauNoeud);
			dernierNoeud = nouveauNoeud;
			longueurSousChaine++;
		}
	}
	return lexique;
}

std::unique_ptr<Lexique> UsineLexique::initialiserLexiqueOptimise1(std::string nomFichier)
{
	std::ifstream fichier;
	fichier.open(nomFichier);
	if (!fichier.is_open()) throw std::runtime_error("Le fichier n'a pu être ouvert, vérifier le chemin d'accès.");

	// cree un arbre unique pour chaque lettre
	std::string buffer, sousChaine;
	std::unique_ptr<Lexique> lexique(new Lexique());
	while (std::getline(fichier, buffer)) {

		auto nouveauNoeud = std::make_shared<Noeud>(buffer.substr(0, 1), false, 1);	//premiere lettre
		auto dernierNoeud = nouveauNoeud;

		std::vector<std::shared_ptr<Noeud>>::iterator it = lexique->lettresArbres_.begin();
		while (
			it != lexique->lettresArbres_.end() && 
			(*it)->obtenirValeur() != nouveauNoeud->obtenirValeur()) 
		{
			it++;
		}
		if (it == lexique->lettresArbres_.end()) {
			lexique->lettresArbres_.push_back(nouveauNoeud);
		}
		else {
			dernierNoeud = *it;
		}
		unsigned int longueurSousChaine = 2;
		while (longueurSousChaine <= buffer.length()) {	// generer les sous-chaines et les chainer
			sousChaine = buffer.substr(0, longueurSousChaine);
			nouveauNoeud = std::make_shared<Noeud>(sousChaine, false, longueurSousChaine);
			dernierNoeud->ajouterEnfant(nouveauNoeud);
			dernierNoeud = nouveauNoeud;
			longueurSousChaine++;
		}
		dernierNoeud->marquerUnMot();
	}
	return lexique;
}