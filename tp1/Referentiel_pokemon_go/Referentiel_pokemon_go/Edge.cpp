#include "Edge.h"
#include "Node.h"
#include <iostream>


Edge::Edge(std::shared_ptr<Node> node1, std::shared_ptr<Node> node2, double length)
	:firstNode_(node1), secondNode_(node2), length_(length)
{
}


Edge::~Edge()
{
}

void Edge::setFirstNode(std::shared_ptr<Node> node){
    firstNode_ = node;
}

void Edge::setSecondNode(std::shared_ptr<Node> node){
    secondNode_ = node;
}

void Edge::setLength(double length){
    length_ = length;
}

std::shared_ptr<Node> Edge::getFirstNode()const{
    return firstNode_;
}

std::shared_ptr<Node> Edge::getSecondNode()const{
    return secondNode_;
}

double Edge::getLength()const {
    return length_;
}

//! A function to find the other Node attached to the current Edge
/*!
 * \param node : the first node that we know that is attached to the edge. 
 * \result : The other node of the current edge.
 */
std::shared_ptr<Node> Edge::getOtherNode(const std::shared_ptr<Node> node) const{
    if (node == firstNode_)
        return secondNode_;
    else if (node == secondNode_){
        return firstNode_;
    }
    else return nullptr;
}


