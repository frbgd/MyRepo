#include<iostream>
using namespace std;

class MyException : public exception{
	int number;
public:
	MyException(const char *msg, int number) :exception(msg) {
		this->number = number;
	}
	int GetNumber() { return number; }
};

void Foo(int value) {
	if (value == 0) {
		throw exception("a null");
	}
	if (value < 0) {
		throw MyException("a number less than null", value);
	}
	cout << "Number = " << value << endl;
}

int main() {
	try {
		Foo(-1);
	}
	catch (MyException &ex) {
		cout << "We catched " << ex.what() << endl;
		cout << "Number = " << ex.GetNumber() << endl;
	}
	catch (exception &ex) {
		cout << "We catched " << ex.what() << endl;
	}
	system("pause");
	return 0;
}