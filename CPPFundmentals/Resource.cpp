#include "Resource.h"
#include<iostream>

using std::string;
using std::cout;
using std::endl;

Resource::Resource(string _name):name(_name)
{
	cout << "Constructing " << name << endl;
}

Resource::~Resource(void)
{
	cout << "Destructing " << name << endl;
}