#pragma once
#include<string>

class Resource
{
private:
	std::string name;
public:
	Resource(std::string _name);
	~Resource(void);
	std::string GetName() const { return name; }
};