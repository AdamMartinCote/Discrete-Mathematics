#pragma once

// forward declarations
class Node;

class Edge
{
public:
	Edge();
	~Edge();
private:
	Node* firstNode;
	Node* secondNode;
	double length;
};

