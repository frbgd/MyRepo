// данный пример перехватывает все исключения
#include <iostream>
using namespace std;

void Xhandler(int test)
{
	try {
		if (test == 0) throw test; // генерация int
		if (test == 1) throw 'a'; // генерация char
		if (test == 2) throw 123.23; // генерация double
	}
	catch (...) { // перехват всех исключений
		cout << "Caught One!\n";
	}
}
int main()
{
	cout << "Start\n";
	Xhandler(0);
	Xhandler(1);
	Xhandler(2);
	cout << "End" << endl;
	system("pause");
	return 0;
}