#include <iostream>
#include <conio.h>
#include <string>
#include <list>
#include <vector>

using std::string;
using std::list;
using std::vector;
using std::cout;
using std::endl;

class Widget
{
public:
	~Widget() {}
};

void doSomething()
{
	std::vector<Widget> v;
}

class DBConnection
{
public:
	static DBConnection create();

	void close();
};

class DBConn
{
public:
	DBConn(DBConnection) {}

	~DBConn()
	{
		try
		{
			db.close();
		}
		catch (...)
		{
			std::abort();
		}
	}
private:
	DBConnection db;
};

class DBConn1
{
public:
	void close()
	{
		db.close();
		closed = true;
	}

	~DBConn1()
	{
		if (!closed)
		{
			try
			{
				db.close();
			}
			catch (...)
			{

			}
		}
	}
private:
	DBConnection db;
	bool closed;
};

int main()
{
	DBConn dbc(DBConnection::create());

	cout << "press any key to exit\n";
	_getch();

	return 0;
}
