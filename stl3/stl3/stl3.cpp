//iterator
#include <iostream>
#include<vector>

using namespace std;

int main() {
	vector<int> myVector = { 1,9,44,422,676,78 };
	vector<int>::iterator it;
	it = myVector.begin();	//этот метод даёт доступ к первому элементу вектора
	it+=2;
	cout << *it << endl;	//44
	it--;
	cout << *it << endl << endl;	//9
	for (vector<int>::iterator i = myVector.begin(); i != myVector.end(); i++)
		cout << *i << endl;
	system("pause");
	return 0;
}