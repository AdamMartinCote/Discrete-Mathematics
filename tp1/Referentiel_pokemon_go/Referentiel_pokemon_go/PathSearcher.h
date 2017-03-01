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

	//! A function that prints the maximum gain given the maximum length
	/*!
	* \param theGraph_ : the graph on which we calculate the biggest gain
	* \param startNode : The starting node
	* \param maximumLength : The maximum lenght we can travel
	* \result : A string the path with the biggest gain
	*/
	static std::string ObtainBiggestGain(std::shared_ptr<Graph> theGraph_, std::shared_ptr<AbstractNode> startNode, unsigned int maximumLength);

private:

	static std::shared_ptr<Edge> PathSearcher::NextshortestEdge(std::shared_ptr<AbstractNode> node, std::vector<std::shared_ptr<AbstractNode>> nodesIncluded);
};