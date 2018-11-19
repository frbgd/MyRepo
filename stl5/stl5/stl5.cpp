//iterator
#include <iostream>
#include<vector>

using namespace std;

int main() {
	vector<int> myVector = { 1,9,44,422,676,78 };
	vector<int>::iterator it = myVector.begin();
	for (vector<int>::iterator i = myVector.begin(); i != myVector.end(); i++)
		cout << *i << endl;
	cout << endl;
	it++;
	myVector.insert(it, 888);
	for (vector<int>::iterator i = myVector.begin(); i != myVector.end(); i++)
		cout << *i << endl;
	cout << endl;
	vector<int>::iterator erit = myVector.begin();
	myVector.erase(erit);
	for (vector<int>::iterator i = myVector.begin(); i != myVector.end(); i++)
		cout << *i << endl;
	system("pause");
	return 0;
}