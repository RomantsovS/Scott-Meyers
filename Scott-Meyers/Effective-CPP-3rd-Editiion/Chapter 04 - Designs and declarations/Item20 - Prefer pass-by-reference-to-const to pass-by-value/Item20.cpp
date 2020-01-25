#include <iostream>
#include <conio.h>
#include <string>
#include <list>
#include <memory>

using std::string;
using std::list;
using std::cout;
using std::endl;

class Person
{
public:
	Person();
	virtual ~Person();
private:
	string name;
	string address;
};

class Student : public Person
{
public:
	Student();
	virtual ~Student();
private:
	string schoolName;
	string schoolAddress;
};

//bool validateStudent(Student s);
bool validateStudent(const Student &s);

int main()
{
	Student plato;
	bool platosOK = validateStudent(plato);

	cout << "press any key to exit\n";
	_getch();

	return 0;
}
