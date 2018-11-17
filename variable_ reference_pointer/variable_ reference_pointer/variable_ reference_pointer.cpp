#include<iostream>

using namespace std;

void foo1(int a) {
	a = 1;
}

void foo2(int &a) {
	a = 2;
}

void foo3(int *a) {
	*a = 3;
}

int main()
{
	int value = 5;
	cout << "value = " << value << endl;
	foo1(value);
	cout << "foo1\tvalue = " << value << endl;
	foo2(value);
	cout << "foo2\tvalue = " << value << endl;
	foo3(&value);
	cout << "foo3\tvalue = " << value << endl;
	system("pause");
	return 0;
}