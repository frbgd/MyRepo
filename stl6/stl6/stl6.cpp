//functor
#include<iostream>

using namespace std;

class MyFuntor {
public:
	int operator ()(int a, int b) {
		cout << "I'm functor " << endl;
		return a + b;
	}
};

class EvenFuntor {
	int evenSum = 0;
	int evenCount = 0;
public:
	void ShowEvenSum() {
		cout << "Even sum = " << evenSum << endl;
	}
	void ShowEvenCount() {
		cout << "Even count = " << evenCount << endl;
	}
	void operator()(int value) {
		if (value % 2 == 0) {
			evenSum += value;
			evenCount++;
		}
	}
};

int main() {
	int arr[] = { 1,2,55,99,44,3 };
	EvenFuntor ef;
	for (auto element : arr) {
		ef(element);
	}
	ef.ShowEvenCount();
	ef.ShowEvenSum();
	system("pause");
	return 0;
}