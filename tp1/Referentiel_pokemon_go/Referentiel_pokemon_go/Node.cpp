#include "Node.h"



Node::Node(int gain, int respawnLength)
	:gain_(gain), respawnLength_(respawnLength), isActive_(true)
{
}


Node::~Node()
{
}
