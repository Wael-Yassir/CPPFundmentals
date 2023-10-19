
#include "PersonChild.h"

PersonChild::PersonChild(
	std::string const& firstname, 
	std::string const& lastname, 
	int id, 
	std::string const& handler)	
		: Person(firstname, lastname, id), personChildHandler(handler)
{

}

PersonChild::~PersonChild()
{

}

std::string PersonChild::GetName() const
{
	return Person::GetName() + " " + personChildHandler;
}