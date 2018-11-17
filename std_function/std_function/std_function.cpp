//полиморфная обертка функции
#include<iostream>
#include<functional>
#include<vector>

using namespace std;

void Foo(int a) {
	if (a > 10 && a < 40)
		cout << a << endl;
}

void Bar(int a) {
	if (a % 2 == 0)
		cout << a << endl;
}

int Sum(int a, int b) {
	return a + b; 
}

void DoWork(vector<int> &vc, function<void(int)> f) {
	for (auto e1 : vc)
		f(e1);
}

//void DoWork2(vector<int> &vc) {
//	for (auto e1 : vc)
//		Bar(e1);
//}

int main() {
	vector<int> vc = { 1,51,4,10,44,98,8,12,22,29,49 };
	DoWork(vc, Foo);
	cout << endl;
	DoWork(vc, Bar);
	system("pause");
	return 0;
}