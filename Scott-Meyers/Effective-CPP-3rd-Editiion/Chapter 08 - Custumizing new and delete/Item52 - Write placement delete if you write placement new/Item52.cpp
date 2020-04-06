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

class Widget {
public:
	static void* operator new(std::size_t size, std::ostream& logStream) throw(std::bad_alloc);
	static void operator delete(void* pMemory) throw();
	static void operator delete(void* pMemory, std::ostream& logStream) throw();
};

class Base {
public:
	static void* operator new(std::size_t size, std::ostream& logStream) throw(std::bad_alloc)
	{
		auto ptr = malloc(size);
		return ptr;
	}
};

//Base* pb = new Base;
Base* pb = new(std::cerr) Base;

class Derived : Base {
public:
	static void* operator new(std::size_t size) throw(std::bad_alloc)
	{
		auto ptr = malloc(size);
		return ptr;
	}
};

//Derived* pd = new(std::cerr) Derived;
Derived* pd = new Derived;

class StandartNewDeleteForms {
public:
	//normal new delete
	static void* operator new(std::size_t size) throw(std::bad_alloc) { return ::operator new(size); }
	static void operator delete(void* pMemory) throw() { return ::operator delete(pMemory); }

	//placement new delete
	static void* operator new(std::size_t size, void* ptr) throw() { return ::operator new(size, ptr); }
	static void operator delete(void* pMemory, void* ptr) throw() { return ::operator delete(pMemory, ptr); }

	//nothrow new delete
	static void* operator new(std::size_t size, const std::nothrow_t &nt) throw() { return ::operator new(size, nt); }
	static void operator delete(void* pMemory, const std::nothrow_t& nt) throw() { return ::operator delete(pMemory); }
};

class Widget2 : public StandartNewDeleteForms {
public:
	using StandartNewDeleteForms::operator new;
	using StandartNewDeleteForms::operator delete;

	static void* operator new(std::size_t size, std::ostream& logStream) throw(std::bad_alloc);
	static void operator delete(void* pMemory, std::ostream& logStream) throw();
};

int main()
{

	cout << "press any key to exit\n";
	_getch();

	return 0;
}
