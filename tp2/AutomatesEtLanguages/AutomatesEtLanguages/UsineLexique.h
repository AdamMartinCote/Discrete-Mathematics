#pragma once
#include <fstream>
#include "Lexique.h"

class UsineLexique
{
public:
	UsineLexique();
	~UsineLexique();

	static std::unique_ptr<Lexique> initialiserLexique(std::string nomFichier);
};

