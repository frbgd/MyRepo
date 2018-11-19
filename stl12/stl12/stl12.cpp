//алгоритм поиска
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	vector<int> v = { 6,4,4,12,2 };
	auto result = find(v.begin(), v.end(), 0);
	if (result == v.end()) {
		cout << "-\n";
	}
	else {				//else result == founded element
		cout << "+\n";
	}

	auto result1 = find_if(v.begin(), v.end(), [](int a) {
		return a < 0;
	});
	if (result1 == v.end()) {
		cout << "-\n";
	}
	else {
		cout << "+\n";
	}
	auto result2 = find_if_not(v.begin(), v.end(), [](int a) {
		return a < 0;
	});
	if (result2 == v.end()) {
		cout << "-\n";
	}
	else {
		cout << "+\n";
	}
	system("pause");
	return 0;
}