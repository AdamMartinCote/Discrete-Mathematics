#include <iostream>
#include "test.h"



test::test()
{
}


test::~test()
{
}

void test::listerRacines(Lexique * lexique) {
	// DEBUG verifie si le lexique est bien chargé (affiche les premieres lettres)
	std::cout << "liste des racines obtenue: ";
	for (unsigned int i = 0; i < lexique->obtenirLesArbres().size(); i++) {
		std::cout << lexique->obtenirLesArbres().at(i)->obtenirValeur() << " ";
	}
	std::cout << std::endl;
}

void test::afficherPremierMotDUneRacine(Lexique * lexique, int indexAAfficher) {
	// DEBUG imprime quelque mots du lexique:
	std::cout << "\n sous-arbre [" << indexAAfficher << "]:  ";
	lexique->obtenirLesArbres()[indexAAfficher]->AfficherPremierMotDuSousArbre();

	std::cout << std::endl;
}

void test::testerSiArbreContientDoublons(Lexique * lexique, int indexArbre) {
	

}