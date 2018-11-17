//полиморфная обертка функции
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

void DoWork(vector<int> &vc, vector<function<void(int)>> funcVector) {
	for (auto e1 : vc)
		for (auto &fe1 : funcVector)
			fe1(e1);

}

//void DoWork2(vector<int> &vc) {
//	for (auto e1 : vc)
//		Bar(e1);
//}

int main() {
	vector<int> vc = { 1,51,4,10,44,98,8,12,22,29,49 };
	vector<function<void(int)>> fVector;
	fVector.emplace_back(Foo);
	fVector.emplace_back(Bar);
	fVector.emplace_back(Baz);
	DoWork(vc, fVector);
	system("pause");
	return 0;
}