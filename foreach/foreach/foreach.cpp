//range-based циклы
#include<iostream>
#include<vector>
#include<list>

using namespace std;

template <typename T>
void PrintList(const list<T> &lst) {
	for (auto i = lst.begin(); i != lst.cend(); ++i)
		cout << *i << endl;
}

int main() {
	int arr[] = { 5,11,94,99,44 };
	//for each (auto var in arr){
	//	cout << var << endl;
	//}
	for (auto element : arr) {
		element = -1;
		cout << element << endl;
	}
	for (auto &element : arr) {
		element = -1;
		cout << element << endl;
	}
	for (const auto element : arr) {
		//element = -1;
		cout << element << endl;
	}

	list<int> myList = { 1,9,4,94,799,44,6 };
	for (const auto element : myList) {
		cout << element << endl;
	}
	system("pause");
	return 0;
}