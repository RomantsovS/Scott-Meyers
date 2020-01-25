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

class PrettyMenu
{
public:
	void changeBackGround(std::istream& imgSrc)
	{
		//lock(&mutex);
		Lock ml(&mutex);

		/*delete bgImage;
		++imageChanges;
		bgImage = new Image(imgSrc);*/

		//unlock(&mutex);

		gbImage.reset(new Image(imgSrc));
		++imageChanges;
	}
private:
	Mutex mutex;

	//Image *bgImage;
	std::shared_ptr<Image> gbImage;
	int imageChanges;
};

int main()
{
	cout << "press any key to exit\n";
	_getch();

	return 0;
}
