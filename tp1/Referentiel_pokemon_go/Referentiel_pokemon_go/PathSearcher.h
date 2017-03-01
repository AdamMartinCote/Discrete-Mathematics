#pragma once

#include "Graph.h"
#include "NodeActivity.h"

class PathSearcher
{
public:
#pragma region ConstructorDestructor
	//! A default constructor
	PathSearcher();
	//! A default destructor
	~PathSearcher();
#pragma endregion ConstructorDestructor

	static std::string ObtainShortestPath();

	static std::string ObtainShortestPathWithoutDisjktra(std::shared_ptr<Graph>  theGraph_, std::string startKeyNode, unsigned int gainWanted);

	static std::string ObtainBiggestGain();
};