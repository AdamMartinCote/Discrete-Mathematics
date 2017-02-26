#include <iostream>
#include <string>
#include "AbstractNode.h"
#include "Edge.h"
#include <memory>

AbstractNode::AbstractNode(){}

AbstractNode::AbstractNode(std::string name, int gain)
	:name_(name), gain_(gain), isActive_(true)
{}

AbstractNode::~AbstractNode(){}

void AbstractNode::setGain(int gain) {
	gain_ = gain;
}

void AbstractNode::setRespawnLength(int respawnLength) {
	respawnLength_ = respawnLength;
}

int AbstractNode::getGain() const {
	return gain_;
}

int AbstractNode::getRespawnLength() const {
	return respawnLength_;
}

unsigned int AbstractNode::getEdgeQuantity() const {
	return edgeVector_.size();
}

std::vector<std::shared_ptr<Edge>> AbstractNode::getEdges() const{
    return edgeVector_;
}

void AbstractNode::addEdge(std::shared_ptr<Edge> edge) {
	edgeVector_.push_back(edge);
}

void AbstractNode::printNode() const
{
	std::cout << "("
		<< name_ << ", "
		<< this->getNodeType() << ", "
		<< gain_ << ", (";
	// print edges, omitting the starting node for simplicity
	bool isFirstElement = true;
	for(auto i : edgeVector_)
	{
		if (!isFirstElement) std::cout << ", ";
		std::cout << "(";
		if (i->getFirstNode()->getName() != this->getName()) std::cout << i->getFirstNode()->getName();
		if (i->getSecondNode()->getName() != this->getName()) std::cout << i->getSecondNode()->getName();
		std::cout << ", " << i->getLength() << ")";
		isFirstElement = false;
	}
	std::cout << ")" << std::endl;
}

std::string AbstractNode::getName() const
{
	return name_;
}

bool AbstractNode::isActive() const
{
	return isActive_;
}