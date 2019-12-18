#include <iostream>
#include <conio.h>
#include <string>
#include <list>

#include "TFS.h"

using std::string;
using std::list;
using std::cout;
using std::endl;

class ABEntry
{
public:
	ABEntry();
	ABEntry(const string &name, const string &address, const list<string> &phones);
private:
	string theName;
	string theAddress;
	list<string> thePhones;
	int numTimesConsulted;
};

class Directory
{
public:
	Directory()
	{
		cout << "dir\n";
		//size_t disks = tfs.numDisks();
		size_t disks = tfs().numDisks();
	}
};

Directory &tempDir()
{
	static Directory td;
	return td;
}

int main()
{
	//Directory dir;
	auto dir = tempDir();

	cout << "press any key to exit\n";
	_getch();

	return 0;
}

ABEntry::ABEntry() : theName(), theAddress(), thePhones(), numTimesConsulted(0)
{
}

ABEntry::ABEntry(const std::string & name, const std::string & address, const std::list<std::string>& phones)
	: theName(name), theAddress(address), thePhones(phones), numTimesConsulted(0)
{
}
