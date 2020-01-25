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

class Transaction
{
public:
	Transaction();
	explicit Transaction(const string &logInfo);
	//virtual void logTransaction() const = 0;
	void logTransaction(const string &logInfo) const;
private:
	/*void init()
	{
		logTransaction();
	}*/
};

Transaction::Transaction()
{
	//logTransaction();
	//init();
}

Transaction::Transaction(const string & logInfo)
{
	logTransaction(logInfo);
}

void Transaction::logTransaction(const string & logInfo) const
{
	auto str = logInfo;
}

class BuyTransaction : public Transaction
{
public:
	BuyTransaction(string pars) : Transaction(createLogString(pars)) {}
	//virtual void logTransaction() const override {}
private:
	static string createLogString(string pars);
};

class SellTransaction : public Transaction
{
public:
	//virtual void logTransaction() const override {}
};

int main()
{
	BuyTransaction b("abc");

	cout << "press any key to exit\n";
	_getch();

	return 0;
}

string BuyTransaction::createLogString(string pars)
{
	return string();
}
