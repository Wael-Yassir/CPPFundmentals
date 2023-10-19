#pragma once

#include"Person.h"

class Twitter : public Person
{
private:
	std::string twitterHandler;

public:
	Twitter(std::string const& firstname, std::string const& lastname, int id, std::string const& handler);
	~Twitter();
};
