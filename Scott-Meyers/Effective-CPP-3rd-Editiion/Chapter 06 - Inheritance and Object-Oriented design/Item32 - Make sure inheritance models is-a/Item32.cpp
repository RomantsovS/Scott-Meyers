#include <iostream>
#include <conio.h>
#include <string>
#include <list>
#include <memory>
#include <vector>

using std::string;
using std::list;
using std::cout;
using std::endl;

class Person {};

class Student : public Person {};

void eat(const Person &p);
void study(const Student& s);

int main()
{
	Person p;
	Student s;

	eat(p);
	eat(s);

	study(s);
	//study(p);

	cout << "press any key to exit\n";
	_getch();

	return 0;
}
