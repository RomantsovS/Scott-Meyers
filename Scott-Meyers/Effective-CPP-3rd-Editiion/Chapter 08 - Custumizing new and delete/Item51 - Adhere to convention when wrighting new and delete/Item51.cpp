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

class Base {
public:
	static void* operator new(std::size_t size) throw(std::bad_alloc);
	static void operator delete(void *rawMemory, std::size_t size) throw();
};

class Derived : public Base
{};

Derived* p = new Derived;

void* Base::operator new(std::size_t size) throw(std::bad_alloc)
{
	if (size != sizeof(Base))
		return ::operator new(size);
}

void Base::operator delete(void* rawMemory, std::size_t size) throw()
{
	if (rawMemory == 0) return;

	if (size != sizeof(Base)) {
		::operator delete(rawMemory);
		return;
	}

	return;
}

int main()
{

	cout << "press any key to exit\n";
	_getch();

	return 0;
}
