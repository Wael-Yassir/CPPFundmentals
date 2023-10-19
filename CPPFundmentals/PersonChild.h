#pragma once

#include "Person.h"

class PersonChild : public Person
{
private:
	std::string personChildHandler;

public:
	PersonChild(
		std::string const& firstname, 
		std::string const& lastname, 
		int id, 
		std::string const& handler);
	~PersonChild();
	std::string GetName() const;
};
