#ifndef PERSON_H
#define PERSON_H

#include <string>

#include "PersonImpl.h"
#include "Date.h"

using std::string;

class Person
{
public:
	/*Person(const string & name, const Date& birthday,
		const Address& addr)
		: pimpl(new PersonImpl(name, birthday, addr)) {}*/
	virtual ~Person() {}

	/*string name() const;
	string birthDate() const;
	string address() const;*/

	virtual string name() const = 0;
	virtual Date birthDate() const = 0;
	virtual Address address() const = 0;

	static std::shared_ptr<Person> create(
		const string & name, const Date& birthday,
		const Address& addr);
private:
	/*string theName;
	Date theBirhtDate;
	Address theAddress;*/
	std::shared_ptr<PersonImpl> pimpl;
};

class RealPerson : public Person
{
public:
	RealPerson(const string & name, const Date& birthday,
		const Address& addr) : theName(name) {}

	~RealPerson() {}

	string name() const { return theName; }
	Date birthDate() const { return Date();}
	Address address() const { return Address(); }
private:
	string theName;
	Date theBirhtDate;
	Address theAddress;
};


#endif