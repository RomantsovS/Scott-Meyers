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

/*template<typename t, std::size_t n>
class SquareMatrix {
public:
	void invert();
};*/

template<typename T>
class SquareMatrixBase {
protected:
	SquareMatrixBase(size_t n, T* pMem) : size(n), pData(pMem) {}

	void setDataPtr(T* ptr) { pData = ptr; }
private:
	size_t size;
	T* pData;
public:
	void invert(size_t matrixSize);
};

template<typename T, std::size_t n>
class SquareMatrix : private SquareMatrixBase<T> {
private:
	using SquareMatrixBase<T>::invert;
	std::array<T> pData;
public:
	SquareMatrix() : SquareMatrixBase<T>(n, 0), pData(new T[n*n])
	{
		this->setDataPtr(pData.get());
	}

	void invert()
	{
		invert(n);
	}
};

int main()
{
	cout << "press any key to exit\n";
	_getch();

	return 0;
}
