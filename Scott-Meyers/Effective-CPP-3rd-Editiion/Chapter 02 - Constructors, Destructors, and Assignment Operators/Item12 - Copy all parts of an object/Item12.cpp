#include <iostream>
#include <conio.h>
#include <string>
#include <list>
#include <vector>

using std::string;
using std::list;
using std::vector;
using std::cout;
using std::endl;

void logCall(const string & funcName);

class Date {};

class Customer
{
public:
	Customer(const Customer &rhs) : name(rhs.name)
	{
		logCall("Customer copy construct");
	}

	Customer & operator=(const Customer &rhs)
	{
		logCall("Customer copy assignment operator");
		name = rhs.name;

		return *this;
	}
private:
	string name;
	Date lastTransaction;
};

class PriorityCustomer : public Customer
{
public:
	PriorityCustomer(const PriorityCustomer &rhs)
		: Customer(rhs), priority(rhs.priority)
	{
		logCall("PriorityCustomer copy construct");
	}

	PriorityCustomer & operator=(const PriorityCustomer &rhs)
	{
		logCall("PriorityCustomer copy assignment operator");
		
		Customer::operator=(rhs);
		priority = rhs.priority;

		return *this;
	}
private:
	int priority;
};

int main()
{

	cout << "press any key to exit\n";
	_getch();

	return 0;
}