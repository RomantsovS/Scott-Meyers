#include <iostream>
#include <conio.h>
#include <string>
#include <list>
#include <memory>
#include <vector>

#include "Date.h"
#include "Person.h"

using std::string;
using std::list;
using std::cout;
using std::endl;

int main()
{
	//Person p("asd", Date(), Address());
	//cout << p.name() << endl;
	std::shared_ptr<Person> p(Person::create("asd", Date(), Address()));
	cout << p->name() << endl;
	

	cout << "press any key to exit\n";
	_getch();

	return 0;
}

std::shared_ptr<Person> Person::create(const string & name,
	const Date & birthday, const Address & addr)
{
	return std::shared_ptr<Person>(new RealPerson(name,
		birthday, addr));
}
