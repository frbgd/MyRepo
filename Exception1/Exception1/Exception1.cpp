// пример обработки простого исключения
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
	catch (int i) { // перехват ошибки
		cout << "Caught an exception -- value is: ";
		cout << i << " \n";
	}
	cout << "End" << endl;
	system("pause");
	return 0;
}