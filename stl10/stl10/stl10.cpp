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
	const int size = 7;
	int arr[size] = { 9,4,64,6,1,3,7 };
	sort(arr, arr + size);				//алгоритм сортировки
	for (auto element : arr)
		cout << element << endl;
	cout << endl;
	sort(arr, arr + size, MyPred);
	for (auto element : arr)
		cout << element << endl;
	cout << endl;
	sort(arr, arr + size, [](int a, int b) {
		return a > b;
	});
	for (auto element : arr)
		cout << element << endl;
	system("pause");
	return 0;
}