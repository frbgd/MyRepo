//предикат
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

bool MyPred(int a, int b) {				//бинарный предикат
	return a > b;
}

int main() {
	vector<int> v = { 9,4,64,6,1,3,7 };
	sort(v.begin(), v.end());
	for (auto element : v)
		cout << element << endl;
	cout << endl;
	sort(v.begin(), v.end(), MyPred);
	for (auto element : v)
		cout << element << endl;
	cout << endl;
	sort(v.begin(), v.end(), [](int a, int b) {		//предикат - лямбда-функция
		return a > b;
	});
	for (auto element : v)
		cout << element << endl;
	system("pause");
	return 0;
}