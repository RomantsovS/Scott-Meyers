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

static const int signature = 0xDEADBEEF;

typedef unsigned char Byte;

void* operator new(std::size_t size) throw(std::bad_alloc)
{
	using namespace std;

	size_t realSize = size + 2 * sizeof(int);

	void* pMem = malloc(realSize);
	if (!pMem)
		throw bad_alloc();

	*(static_cast<int*>(pMem)) = signature;
	*(reinterpret_cast<int*>(static_cast<Byte*>(pMem) + realSize + sizeof(int))) = signature;

	return static_cast<Byte*>(pMem) + sizeof(int);
}

int main()
{

	cout << "press any key to exit\n";
	_getch();

	return 0;
}
