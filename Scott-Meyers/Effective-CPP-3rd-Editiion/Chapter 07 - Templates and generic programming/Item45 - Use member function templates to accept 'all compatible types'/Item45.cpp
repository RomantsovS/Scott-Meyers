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

class Top {};
class Middle : public Top {};
class Bottom : public Middle {};

Top* pt1 = new Middle;
Top* pt2 = new Bottom;

const Top* pct2 = pt1;

template <typename T>
class SmartPtr {
public:
	explicit SmartPtr(T* realPtr);

	template<typename U>
	SmartPtr(const SmartPtr<U>& other) : heldPtr(other.get()) {}
	T* get() const { return heldPtr; }
private:
	T* heldPtr;
};

SmartPtr<Top> pt1 = SmartPtr<Middle>(new Middle);
SmartPtr<Top> pt2 = SmartPtr<Middle>(new Bottom);
SmartPtr<const Top> pct2 = pt1;

int main()
{
	cout << "press any key to exit\n";
	_getch();

	return 0;
}
