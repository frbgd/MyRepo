#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void Foo(int a) {
	cout << a << endl;
}

int main() {
	vector<int> v = { 1,2,10,55 };
	for_each(v.begin(), v.end(), Foo);		//алгоритм
	cout << endl;
	for (auto a : v) {		//цикл
		Foo(a);
	}
	cout << endl;
	for_each(v.begin(), v.end(), [](int a) {
		cout << a << endl;
	});
	cout << endl;
	for_each(v.begin(), v.end(), [](int &a) {
		cout << a << endl;
		a++;
	});
	cout << endl;
	for_each(v.begin(), v.end(), [](int a) {
		cout << a << endl;
	});
	system("pause");
	return 0;
}