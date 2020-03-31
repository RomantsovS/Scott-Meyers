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

class BorrwoableItem {
public:
	void checkOut();
};

class ElectronicGadget{
private:
	void checkOut() const;
};

class MP3Player : public BorrwoableItem, public ElectronicGadget {};

MP3Player mp;
//mp.checkOut();
mp.BorrwoableItem::checkOut();

class File {};
class InputFile : virtual public File {};
class OutputFile : virtual public File {};
class IOFile : public InputFile, public OutputFile {};

class IPerson {
public:
	virtual ~IPerson();
	virtual std::string name() const = 0;
	virtual std::string birthDate() const = 0;
};

class DatabaseID {};

std::shared_ptr<IPerson> makePerson(DatabaseID personIdentifier);
DatabaseID askUserForDatabaseID();
DatabaseID id(askUserForDatabaseID());

std::shared_ptr<IPerson> pp(makePerson(id));

class PersonInfo {
public:
	explicit PersonInfo(DatabaseID pid);
	virtual ~PersonInfo();

	virtual const char* theName() const
	{
		static char value[Max_Formatted_Field_Value_Lenght];

		std::strcpy(value, valueDelimOpen());

		std::strcat(value, valueDelimClose());
	}

	virtual const char* theBirthDate() const;
private:
	const size_t Max_Formatted_Field_Value_Lenght = 50;

	virtual const char* valueDelimOpen() const
	{
		return "[";
	}

	virtual const char* valueDelimClose() const
	{
		return "]";
	}
};

class CPerson : public IPerson, private PersonInfo {
public:
	explicit CPerson(DatabaseID pid) : PersonInfo(pid) {}

	virtual std::string name() const
	{
		return PersonInfo::theName();
	}

	virtual std::string birthDate() const
	{
		return PersonInfo::theBirthDate();
	}
private:
	const char* valueDelimOpen() const { return ""; }
	const char* valueDelimClose() const { return ""; }
};

int main()
{
	cout << "press any key to exit\n";
	_getch();

	return 0;
}
