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

class Timer {
public:
	explicit Timer(int tickFrequency);
	virtual void onTick() const;
};

/*class Widget : private Timer {
private:
	virtual void onTick() const override;
};*/

class Widget {
private:
	class WidgetTimer : public Timer {
	public:
		virtual void onTick() const override;
	};
	WidgetTimer timer;
};

int main()
{
	cout << "press any key to exit\n";
	_getch();

	return 0;
}
