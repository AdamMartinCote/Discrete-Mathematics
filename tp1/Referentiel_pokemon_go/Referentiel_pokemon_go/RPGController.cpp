#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "RPGController.h"


RPGController::RPGController()
{
}


RPGController::~RPGController()
{
}

void RPGController::updateMap()
{
	
}

Graph RPGController::creerGraphe(std::string fileName)
{
	std::ifstream inputFile;
	inputFile.open(fileName);
	if (inputFile.is_open()) {
		std::string word;
		while (std::getline(inputFile, word, ';'))
		{
			std::cout << word << std::endl;
		}
	}
	return Graph();	// mock
}

void RPGController::lireGraphe()
{
}

void RPGController::plusCourtChemin()
{
}

void RPGController::plusGrandGain()
{
}
