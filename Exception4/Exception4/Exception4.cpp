// обработка исключения внутри функции, в которой сгенерировано исключение

#include <iostream>
using namespace std;

void Xhandler(int test)
{
	try {
		if (test) throw test;
	}
	catch (int i) {
		cout << "Caught Exception #: " << i << '\n';
	}
}
int main()
{
	cout << "Start\n";
	Xhandler(1);
	Xhandler(2);
	Xhandler(0);
	Xhandler(3);
	cout << "End" << endl;
	system("pause");;
	return 0;
}