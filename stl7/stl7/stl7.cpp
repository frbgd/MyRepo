//предикат
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool GreaterThanZero(int i) {		//предикат
	return i > 0;
}

int main() {
	vector<int> v = { 1,-2,-55,9,-3,8 };
	auto result = count_if(v.begin(), v.end(), GreaterThanZero);	//алгоритм count_if считает что-либо в коллекции
	cout << result << endl;
	system("pause");
	return 0;
}