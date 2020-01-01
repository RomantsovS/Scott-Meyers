#include <iostream>
#include <conio.h>

#include <exception>
#include <new>

using std::cout;
using std::endl;

class Base
{
public:
	static void * operator new(size_t size)
	{
		using namespace std;

		if (size == 0)
			size = 1;

		auto s = sizeof(Base);

		while (true)
		{
			auto ptr = malloc(size);

			if (ptr)
				return ptr;

			auto globalHandler = set_new_handler(0);
			set_new_handler(globalHandler);

			if (globalHandler)
				(*globalHandler)();
			else
				throw bad_alloc();
		}
	}

	static void operator delete(void *raw_memory, size_t size)
	{
		if (!raw_memory)
			return;

		if (size != sizeof(Base))
			::operator delete(raw_memory);

		free(raw_memory);
	}
private:
	int a[10];
};

class Derived : public Base
{
private:
	int b[10];
};

int main()
{
	for (int i = 0; i != 1; ++i)
	{
		try
		{
			Base *b = new Derived;

			delete b;
		}
		catch (std::bad_alloc &err)
		{
			cout << err.what() << endl;
		}
	}

	cout << "press any key to exit\n";
	_getch();

	return 0;
}