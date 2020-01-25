#ifndef PERSON_IMPL_H
#define PERSON_IMPL_H

#include <string>

#include "Date.h"

class PersonImpl
{
public:
	PersonImpl(const std::string & name, const Date& birthday,
		const Address& addr) : theName(name) {}

	std::string name() const;
private:
	std::string theName;
	Date theBirhtDate;
	Address theAddress;
};

#endif