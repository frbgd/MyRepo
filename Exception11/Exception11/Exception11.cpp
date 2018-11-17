#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void Foo(int value) {
	if (value < 0) {
		throw "a number less than zero";
	}
	cout << "Value = " << value << endl;
}

int main() {
	try {
		Foo(-55);
	}
	catch (const char *ex) {
		cout << "We cathed " << ex << endl;
	}
	system("pause");
	return 0;
}