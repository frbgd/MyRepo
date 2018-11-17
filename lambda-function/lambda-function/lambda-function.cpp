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

//void DoWork2(vector<int> &vc) {
//	for (auto e1 : vc)
//		Bar(e1);
//}

int main() {
	vector<int> vc = { 1,51,4,10,44,98,8,12,22,29,49 };
	function<void(int)> f;
	f = [](int a) {
		cout << "anonymous function called with parameter " << a << endl;
	};
	DoWork(vc, f);
	cout << endl;
	DoWork(vc, [](int a) {
		cout << "anonymous function called with parameter " << a << endl;
	});
	system("pause");
	return 0;
}