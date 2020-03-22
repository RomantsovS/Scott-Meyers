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


template<class T>
class Set {
public:
	bool member(const T& item) const;

	void insert(const T& item);
	void remove(const T& item);

	std::size_t size() const;
private:
	std::list<T> rep;
};

template <typename T>
bool Set<T>::member(const T& item) const
{
	return std::find(rep.cbegin(), rep.cend, item) != rep.cend();
}

template <typename T>
void Set<T>::insert(const T& item)
{
	if (!member(item))
		rep.push_back(item);
}

template <typename T>
void Set<T>::remove(const T& item)
{
	auto iter = std::find(rep.begin(), rep.end(), item);
	if (!iter)
		rep.erase(iter);
}

template<class T>
std::size_t Set<T>::size() const
{
	return rep.size();
}

int main()
{
	cout << "press any key to exit\n";
	_getch();

	return 0;
}
