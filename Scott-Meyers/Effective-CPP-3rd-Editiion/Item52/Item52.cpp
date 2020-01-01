#include <iostream>
#include <conio.h>

#include <exception>
#include <new>

using std::cout;
using std::endl;

int main()
{
	for (int i = 0; i != 1; ++i)
	{
		try
		{
			
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