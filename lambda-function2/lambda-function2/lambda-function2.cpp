//Лямбда-выражения | Лямбда функции | Анонимные функции
#include<iostream>
#include<functional>
#include<vector>

using namespace std;

void Foo(int a) {
	if (a > 10 && a < 40)
		cout << "Foo " << a << endl;
}

void Bar(int a) {
	if (a % 2 == 0)
		cout << "Bar " << a << endl;
}

void Baz(int a) {
	cout << "Baz\n";
}

int Sum(int a, int b) {
	return a + b;
}

void DoWork(vector<int> &vc, function<void(int)> func) {
	for (auto e1 : vc)
		func(e1);

}

int main() {
	auto f = []() {
		return true;
	};
	auto q = f();
	system("pause");
	return 0;
}