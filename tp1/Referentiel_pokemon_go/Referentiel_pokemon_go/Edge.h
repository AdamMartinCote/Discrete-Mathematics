#pragma once
#include <memory>

class Node;

class Edge
{
public:
	Edge::Edge(std::shared_ptr<Node> node1, std::shared_ptr<Node> node2, double length);
	~Edge();
        
    void setFirstNode(std::shared_ptr<Node> node);
    void setSecondNode(std::shared_ptr<Node> node);
    void setLength(double length);
       
	std::shared_ptr<Node> getFirstNode() const;
	std::shared_ptr<Node> getSecondNode() const;
    double getLength() const;
	std::shared_ptr<Node> getOtherNode(const std::shared_ptr<Node> node) const;

private:
	std::shared_ptr<Node> firstNode_;
	std::shared_ptr<Node> secondNode_;
	double length_;
};

