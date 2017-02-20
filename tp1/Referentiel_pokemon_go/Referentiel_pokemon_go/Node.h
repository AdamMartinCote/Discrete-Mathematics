#pragma once
#include<vector>

// forward declarations
class Edge;

class Node
{
public:
    Node();
    Node(int gain, int respawnLength);
    virtual ~Node();
        
    void setGain(int gain);
    void setRespawnLength(int respawnLength);
    int getGain();
    int getRespawnLength();
private:
    bool isActive_;
    int gain_;
    int respawnLength_;

	std::vector<Edge*> edgeVector;
};
