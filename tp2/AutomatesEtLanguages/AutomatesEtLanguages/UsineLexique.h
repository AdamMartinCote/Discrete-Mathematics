#pragma once
#include <fstream>
#include "Lexique.h"

class UsineLexique
{
public:
	UsineLexique();
	~UsineLexique();

	static std::unique_ptr<Lexique> initialiserLexique(std::string nomFichier);
	static std::unique_ptr<Lexique> initialiserLexiqueOptimise1(std::string nomFichier);
};

