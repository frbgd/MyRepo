#include <iostream>
using namespace std;

void divide(double a, double b);
int main()
{
	double i, j;
	do {
		cout << "Enter numerator (0 to stop): ";
		cin >> i;
		if (i == 0)
			break;
		cout << "Enter denominator: ";
		cin >> j;
		divide(i, j);
	} while (true);
	system("pause");
	return 0;
}
void divide(double a, double b)
{
	try {
		if (!b) throw b; // проверка на деление на ноль
		cout << "Result: " << a / b << endl;
	}
	catch (double b) {
		cout << "Can't divide by zero.\n";
	}
}