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

template <typename C>
void print2nd(const C& container)
{
	if (container.size() >= 2) {
		typename C::const_iterator iter(container.begin());
		++iter;
		int value = *iter;
		std::count << value;
	}
}

template <typename T>
class Base {
public:
	class Nested {
	public:
		Nested(T x = 0) : a(x) {}
	private:
		T a;
	};
};

template<typename T>
class Derived : public Base<T>::Nested {
public:
	explicit Derived(int x) : Base<T>::Nested(x)
	{
		typename Base<T>::Nested temp;
	}
};

template <typename IterT>
void workWithIterator(IterT iter)
{
	typedef typename std::iterator_traits<IterT>::value_type value_type;
	value_type temp(*iter);
}

int main()
{
	Derived<int> d(1);

	cout << "press any key to exit\n";
	_getch();

	return 0;
}
