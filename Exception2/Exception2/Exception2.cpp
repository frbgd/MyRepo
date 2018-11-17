// данный пример не будет работать
#include <iostream>
using namespace std;

int main()
{
	cout << "Start\n";
	try { // начало блока try
		cout << "Inside try block\n";
		throw 100; // генерация ошибки
		cout << "This will not execute";
	}
	catch (double i) { // не будет работать для целочисленного исключения
		cout << "Caught an exception -- value is: ";
		cout << i << "\n";
	}
	cout << "End" << endl;
	system("pause");
	return 0;
}