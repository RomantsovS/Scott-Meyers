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

int defaultHealthCalc(const GameCharacter&);

class GameCharacter
{
public:
	//virtual int healthValue() const;
	/*int healhtValue() const
	{
		int retVal = doHealthValue();
		return retVal;
	}*/
	typedef int(*HealthCalcFunc)(const GameCharacter&);
	explicit GameCharacter(
		HealthCalcFunc hcf = defaultHealthCalc)
		: healthFunc(hcf) {}
	int healthValue() const
	{
		return healthFunc(*this);
	}
private:
	//virtual int doHealthValue() const

	HealthCalcFunc healthFunc;
};

class EvilBadGuy : public GameCharacter
{
public:
	explicit EvilBadGuy(HealthCalcFunc hcf = defaultHealthCalc)
		: GameCharacter(hcf) {}
};

int loseHealthQuickly(const GameCharacter&);
int loseHealthSlowly(const GameCharacter&);

int main()
{
	EvilBadGuy ebg1(loseHealthQuickly);
	EvilBadGuy ebg2(loseHealthSlowly);

	cout << "press any key to exit\n";
	_getch();

	return 0;
}
