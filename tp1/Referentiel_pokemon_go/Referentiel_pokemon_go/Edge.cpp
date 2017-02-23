#include "Edge.h"
#include "Node.h"



Edge::Edge()
{
}


Edge::~Edge()
{
}

void Edge::setFirstNode(Node* node){
    firstNode_ = node;
}

void Edge::setSecondNode(Node* node){
    secondNode_ = node;
}

void Edge::setLength(double length){
    length_ = length;
}

Node* Edge::getFirstNode(){
    return firstNode_;
}

Node* Edge::getSecondNode(){
    return secondNode_;
}

double Edge::getLength(){
    return length_;
}

//! A function to find the other Node attached to the current Edge
/*!
 * \param node : the first node that we know that is attached to the edge. 
 * \result : The other node of the current edge.
 */
Node* Edge::getOtherNode(Node* node){
    if (node == firstNode_)
        return secondNode_;
    else if (node == secondNode_){
        return firstNode_;
    }
    else return nullptr;
}