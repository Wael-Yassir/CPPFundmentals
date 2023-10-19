#include<string>
using std::string;

#include<iostream>
using std::cout;

#include "Person.h"

Person::Person()
{
	cout << "The constructor has been called \n";
}

Person::~Person()
{
	cout << "The desctructor has been called \n";
	delete pResource;
}

Person::Person(string const& firstname, string const& lastname, int id)
	: firstName(firstname), lastName(lastname), arbitraryNumber(id)
{

}

bool Person::operator<(Person const& otherPerson) const
{
	return arbitraryNumber < otherPerson.arbitraryNumber;
}

bool Person::operator<(int number) const
{
	return arbitraryNumber < number;
}

//bool operator<(int number, Person const& person)
//{
//	return number < person.GetNumber();
//}

// when friend keyword is used:
bool operator<(int number, Person const& person)
{
	return number < person.arbitraryNumber;
}

void Person::AddResource()
{
	delete pResource;
	pResource = new Resource{ "Resource for " + GetName() };
}

void Person::AddSmartResource()
{
	smResource.reset();
	smResource = std::make_shared<Resource>("Resource for " + GetName());
}

Person::Person(Person const& p)
{
	pResource = new Resource{ p.pResource->GetName() };
}

Person& Person::operator=(const Person& p)
{
	delete pResource;
	pResource = new Resource{ p.pResource ? p.pResource->GetName() : "" };
	return *this;
}