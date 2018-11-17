//Ключевое слово auto
#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<int> myVector = { 11,46,9 };
	vector<int>::iterator it = myVector.begin();
	auto it2 = myVector.begin();
	for (auto it = myVector.begin(); it != myVector.end(); it++)
	{
		cout << *it << endl;
	}
	system("pause");
	return 0;
}