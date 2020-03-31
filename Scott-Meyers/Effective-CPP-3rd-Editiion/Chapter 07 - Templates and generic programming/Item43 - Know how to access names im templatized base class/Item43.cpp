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

class CompanyA {
public:
	void sendCleartext(const std::string& msg);
	void sendEncrypted(const std::string& msg);
};

class CompanyB {
public:
	void sendCleartext(const std::string& msg);
	void sendEncrypted(const std::string& msg);
};

class MsgInfo {};

template<typename Company>
class MsgSender {
public:
	void sendClear(const MsgInfo& info)
	{
		std::string msg;

		Company c;
		c.sendCleartext();
	}

	void sendSecret(const MsgInfo& info)
	{
	}
};

template<typename Company>
class LoggingMsgSender : public MsgSender<Company> {
public:
	using MsgSender<Company>::sendClear;

	void sendClearMsg(const MsgInfo& info)
	{
		//sendClear(info);
		this->sendClear(info);
		MsgSender<Company>::sendClear(info);
	}

	void sendSecret(const MsgInfo& info)
	{
	}
};

class CompanyZ {
public:
	void sendEncrypted(const std::string& msg);
};

template<>
class MsgSender<CompanyZ> {
public:
	void sendSecret(const MsgInfo& info)
	{
	}
};
int main()
{
	cout << "press any key to exit\n";
	_getch();

	return 0;
}
