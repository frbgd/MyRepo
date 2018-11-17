// пример повторной генерации исключения
#include <iostream>
using namespace std;

void Xhandler()
{
	try {
		throw "hello"; // генерация char *
	}
	catch (const char *) { // перехват char *
		cout << "Caught char * inside Xhandler\n";
		throw; // повторная генерация char * извне функции
	}
}
int main()
{
	cout << "Start\n";
	try {
		Xhandler();
	}
	catch (const char *) {
		cout << "Caught char * inside main\n";
	}
	cout << "End" << endl;
	system("pause");
	return 0;
}