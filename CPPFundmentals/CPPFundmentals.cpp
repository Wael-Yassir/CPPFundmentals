#include <iostream>
using std::cout;

#include "Person.h"
#include "PersonChild.h"
#include "Status.h"
#include "Accum.h"
#include "Resource.h"

template<class T>
T max(T const& t1, T const& t2)
{
	return t1 < t2 ? t2 : t1;
}


int main()
{
	Person p1{ "wael", "gazia", 12 };
	cout << p1.GetName() << std::endl;

	Status s = OK;

	FileError fe = FileError::NOT_FOUND;

	NetworkError ne = NetworkError::DISCONNECTED;

	auto n = max(10.4, 14.2);

	Accum<int> integers{ 100 };
	integers += 12;
	integers += 24;

	cout << integers.GetTotal() << std::endl;

	Accum<Person> people{ 0 };
	Person p2{ "Wael", "Gazia", 1 };
	Person p3{ "Ali", "Hassan", 2 };

	people += p2;
	people += p3;

	cout << people.GetTotal() << std::endl;

	// Refrence in c++ is an alias for something else, can only set target when declarting,
	// all actions go through the reference, and cannot be made to refer to somthing else
	Person p4{ "Loka", "Nessan", 4 };
	Person& reference_p4 = p4;

	reference_p4 = Person{ "Loka_ref_update", "Nessan_ref_update", 4 };
	std::string name = reference_p4.GetName();
	std::string name_2 = reference_p4.GetName();

	// A pointer can point to something that exists or not, but can be made to point to something else
	Person p5{ "Hossam", "Lesy", 5 };
	Person* pointer_p5 = &p5;						// create a pointer pointing to the memory address of p4 & to get the address
	std::string name_3 = (*pointer_p5).GetName();		// to access the value in the pointer use *
	std::string name_4 = pointer_p5->GetName();

	int const* pointer_to_const_int = nullptr;				// a pointer that is point to a const integer.
	int* const const_pointer = nullptr;						// a const pointer that is point to a integer.
	int const *const const_pointer_to_const_int = nullptr;	// a const pointer that is point to a integer.


	// When creating an object by default it will be stored in the stack (or local storage)
	// and once the scope of the variable is finish it will be destructed automatically.
	
	{	// you can create a scope in by just put your code in curly praces
		Resource localResource{ "local storage or stack" };
		localResource.GetName();
	}	// destructor will be called after the scope end.
	 
	// If you want the object to stay on the memeroy (called free storage or heap) you nead
	// to store it on the heap by using "new" keyword to do so. This will return a pointer to
	// the object and will the run the constructor to initialize the object. After consuming
	// the object, you can delete it using "delete" keyword and this will call teh destructor too.
	Resource* pResource = new Resource{ "free storage or heap" };
	std::string newString = pResource->GetName(); 
	int j = 3;
	delete pResource;

	cout << std::endl << std::endl;

	Person kate_{ "Kate_", "Georgy", 23 };
	kate_.AddResource();
	kate_.SetFirstName("Kate_2");
	kate_.AddResource();
	Person kate_2 = kate_;

	// To handle the free memory of pointers, a smart pointers can be used
	// unique_ptr => non-copyable
	// shared_ptr => can be copied

	cout << std::endl << std::endl << std::endl;

	Person Kate{ "Kate", "Gregory", 456 };
	Person& rKate = Kate;
	Person* pKate = &Kate;

	PersonChild KateChild{ "Kate", "Gregory", 456, "@gregory" };
	Person& rKateChild = KateChild;
	Person* pKateChild = &KateChild;
	PersonChild& rtKateChild = KateChild;

	cout << rKate.GetName() << std::endl;
	cout << pKate->GetName() << std::endl;
	cout << KateChild.GetName() << std::endl;
	cout << pKateChild->GetName() << std::endl;
	cout << rtKateChild.GetName() << std::endl;
	cout << rKateChild.GetName() << std::endl;

	return 0;
}
