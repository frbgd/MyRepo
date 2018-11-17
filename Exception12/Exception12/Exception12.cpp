#include<iostream>
using namespace std;

void Foo(int value) {
	if (value < 0) {
		throw exception("a number less than zero");
	}
	if (value == 0) {
		throw "a null";
	}
	if (value == 1) {
		throw 1;
	}
	cout << "Value = " << value << endl;
}

int main() {
	try {
		Foo(1);
	}
	catch (const exception &ex) {
		cout << "We cathed " << ex.what() << endl;
	}
	catch (const char *ex) {
		cout << "We cathed " << ex << endl;
	}
	catch (...) {
		cout << "We cathed some exception\n";
	}
	system("pause");
	return 0;
}