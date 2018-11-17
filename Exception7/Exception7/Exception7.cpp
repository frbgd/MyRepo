// ограничение на генерируемые функцией типы
#include <iostream>
using namespace std;

// данная функция может сгенерировать только int, char и double
void Xhandler(int test) noexcept
{
	if (test == 0) throw test; // генерация int
	if (test == 1) throw 'a'; // генерация char
	if (test == 2) throw 123.23; // генерация double
}
int main()
{
	cout << "start\n";
	try {
		Xhandler(0); // попытка передать 1 и 2 в Xhandler()
	}
	catch (int i) {
		cout << "Caught an integer\n";
	}
	catch (char c) {
		cout << "Caught char\n";
	}
	catch (double d) {
		cout << "Caught double\n";
	}
	cout << "end" << endl;
	system("pause");
	return 0;
}