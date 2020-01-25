#include <iostream>
#include <conio.h>
#include <string>
#include <list>
#include <memory>

using std::string;
using std::list;
using std::cout;
using std::endl;

class Mutex {};

void lock(Mutex *pm);
void unlock(Mutex *pm);

class Lock
{
public:
	explicit Lock(Mutex *pm) : mutexPtr(pm, unlock)
	{
		lock(mutexPtr.get());
	}

	/*~Lock()
	{
		unlock(mutexPtr);
	}*/
private:
	//Mutex *mutexPtr;
	std::shared_ptr<Mutex> mutexPtr;
};

int main()
{
	Mutex m;

	{
		Lock ml(&m);
	}

	Lock ml1(&m);
	Lock ml2(ml1);

	cout << "press any key to exit\n";
	_getch();

	return 0;
}
