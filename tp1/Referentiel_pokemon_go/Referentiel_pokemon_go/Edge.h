#pragma once

// forward declarations
class Node;

class Edge
{
public:
	Edge::Edge(Node* node1, Node* node2, double length);
	~Edge();
        
    void setFirstNode(Node* node);
    void setSecondNode(Node* node);
    void setLength(double length);
       
    Node* getFirstNode() const;
    Node* getSecondNode() const;
    double getLength() const;
    Node* getOtherNode(const Node* node) const;

private:
	Node* firstNode_;
	Node* secondNode_;
	double length_;
};

