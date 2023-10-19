// In a header file don't put any using statement.
#pragma once

#include<string>
#include "Resource.h"
#include <memory>

class Person
{
private:
	std::string firstName;
	std::string lastName;
	int arbitraryNumber;
	Resource* pResource = nullptr;

	// using a smart pointer, and when using no need to have a destructor
	std::shared_ptr<Resource> smResource; 


	// friend keyword allow a function to see the private memeber of this class
	// this function is not a part of the class.
	friend bool operator<(int number, Person const& person);

public:
	Person();	// === Person() = default;
	~Person();
	Person(std::string const& firstname, std::string const& lastname, int id);

	// marking a method as virtual means all the child subclasses will call GetName() implemented on
	// them even if you are trying to access the base pointer, and remember once you have one virtual
	// member, you need to mark the destructor as virutal too or the child destructor won't be called
	// if you tried to initialize a child into a pointer to the base class.
	std::string GetName() const { return std::to_string(arbitraryNumber) + " : " + firstName + " " + lastName; };
	
	int GetNumber() const { return arbitraryNumber; };

	// To avoid free memeory issues when copying, we need to define a copy constructor and a copy operator
	Person(Person const& p);
	Person& operator=(const Person& p);

	bool operator<(Person const& otherPerson) const;
	bool operator<(int number) const;

	void SetNumber(int const& number) { arbitraryNumber = number; }
	void SetFirstName(std::string const& fName) { firstName = fName; }
	void SetLastName(std::string const& lName) { lastName = lName; }
	void AddResource();
	void AddSmartResource();

	std::string GetResourceName() const { return pResource ? pResource->GetName() : ""; }
	std::string GetSmartResourceName() const { return smResource ? smResource->GetName() : ""; }
};

//bool operator<(int number, Person const& person);
