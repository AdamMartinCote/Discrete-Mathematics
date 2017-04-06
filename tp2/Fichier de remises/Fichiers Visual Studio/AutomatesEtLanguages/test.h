#pragma once
#include "Lexique.h"
class test
{
public:
	test();
	~test();
	static void listerRacines(Lexique * lexique);
	static void afficherPremierMotDUneRacine(Lexique * lexique, int indexAAfficher);
	static void testerSiArbreContientDoublons(Lexique * lexique, int indexArbre);
};

