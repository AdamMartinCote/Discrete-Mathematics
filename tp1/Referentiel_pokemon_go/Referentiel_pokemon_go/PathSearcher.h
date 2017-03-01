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

	static std::string PathSearcher::ObtainShortestPath(std::shared_ptr<Graph> theGraph_, std::shared_ptr<AbstractNode> startNode, unsigned int gainWanted);

	static std::string ObtainShortestPathWithoutDisjktra(std::shared_ptr<Graph>  theGraph_, std::string startKeyNode, unsigned int gainWanted);

	static std::string ObtainBiggestGain();

private:

	static std::shared_ptr<Edge> PathSearcher::NextshortestEdge(std::shared_ptr<AbstractNode> node, std::vector<std::shared_ptr<AbstractNode>> nodesIncluded);
};