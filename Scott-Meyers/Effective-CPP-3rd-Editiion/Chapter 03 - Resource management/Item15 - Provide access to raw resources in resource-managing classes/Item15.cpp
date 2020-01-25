#include <iostream>
#include <conio.h>
#include <string>
#include <list>
#include <memory>

using std::string;
using std::list;
using std::cout;
using std::endl;

class Investment
{
public:
	bool isTaxFree() const;
};

Investment * createInvestment();

class FontHandle {};

FontHandle getFont();

void releaseFont(FontHandle fh);

class Font
{
public:
	explicit Font(FontHandle fh) : f(fh) {}
	~Font() { releaseFont(f); }

	FontHandle get() const { return f; }
	operator FontHandle() const { return f; }
private:
	FontHandle f;
};

int main()
{
	std::shared_ptr<Investment> pi1(createInvestment());

	bool taxable = !(pi1->isTaxFree());

	cout << "press any key to exit\n";
	_getch();

	return 0;
}
