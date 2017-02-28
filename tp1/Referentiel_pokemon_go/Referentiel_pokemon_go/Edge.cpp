#include "Edge.h"
#include <iostream>

#pragma region ConstructorDestructor
Edge::Edge(std::shared_ptr<AbstractNode> node1, std::shared_ptr<AbstractNode> node2, double length)
	:firstNode_(node1), secondNode_(node2), length_(length)
{
}

Edge::~Edge()
{
}
#pragma endregion ConstructorDestructor

#pragma region Set
void Edge::setFirstNode(std::shared_ptr<AbstractNode> node){
    firstNode_ = node;
}

void Edge::setSecondNode(std::shared_ptr<AbstractNode> node){
    secondNode_ = node;
}

void Edge::setLength(double length){
    length_ = length;
}
#pragma endregion Set

#pragma region Get
std::shared_ptr<AbstractNode> Edge::getFirstNode()const{
    return firstNode_;
}

std::shared_ptr<AbstractNode> Edge::getSecondNode()const{
    return secondNode_;
}

double Edge::getLength()const {
    return length_;
}
#pragma endregion Get

std::shared_ptr<AbstractNode> Edge::getOtherNode(const std::shared_ptr<AbstractNode> node) const{
    if (node == firstNode_)
        return secondNode_;
    else if (node == secondNode_){
        return firstNode_;
    }
    else return nullptr;
}


