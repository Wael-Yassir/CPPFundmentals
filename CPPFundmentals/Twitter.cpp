#include<string>
using std::string;

#include "Twitter.h"


Twitter::Twitter(string const& firstname, string const& lastname, int id, string const& handler)
	: Person(firstname, lastname, id), twitterHandler(handler)
{

}