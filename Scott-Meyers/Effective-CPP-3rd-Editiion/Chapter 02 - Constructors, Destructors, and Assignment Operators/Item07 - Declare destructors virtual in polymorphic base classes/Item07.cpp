#include <iostream>
#include <conio.h>
#include <string>
#include <list>

using std::string;
using std::list;
using std::cout;
using std::endl;

class TimeKeeper
{
public:
	TimeKeeper() {}
	virtual ~TimeKeeper() {}
};

class AtomicClock : public TimeKeeper {};

TimeKeeper * getTimeKeeper()
{
	return new AtomicClock();
}

class AWOV
{
public:
	virtual ~AWOV() = 0;
};

int main()
{
	TimeKeeper *ptk = getTimeKeeper();

	delete ptk;

	cout << "press any key to exit\n";
	_getch();

	return 0;
}
