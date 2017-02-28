#pragma once
#include <string>
#include "AbstractNode.h"

class Arena : public AbstractNode
{
public:
#pragma region ConstructorDestructor
	//! A parametrized constructor
	/*!
	* \param name : The name of the Arena
	* \param gain : The gain of the Arena
	*/
    Arena(std::string name, int gain);
	//! A default destructor
	~Arena();
#pragma endregion ConstructorDestructor

	//! Get the Node type
	/*!
	* \result : The tyoe if the node
	*/
	virtual std::string getNodeType() const override;
};

