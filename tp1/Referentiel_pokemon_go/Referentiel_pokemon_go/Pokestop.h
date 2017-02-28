#pragma once
#include "AbstractNode.h"

class Pokestop : public AbstractNode
{
public:
#pragma region ConstructorDestructor
	//! A parametrized constructor
	/*!
	* \param name : The name of the Pokestop
	* \param gain : The gain of the Pokestop
	*/
	Pokestop(std::string name, int gain);
	//! A default destructor
	~Pokestop();
#pragma endregion ConstructorDestructor

#pragma region Get
	//! Get the name of the Pokestop
	/*!
	* \result : The name of the Pokestop
	*/
	std::string getName() const;
	//! A the type of the Node 
	/*!
	* \result : The type of the Node
	*/
	virtual std::string getNodeType() const override;
#pragma endregion Get
};

