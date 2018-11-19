//iterator
#include <iostream>
#include<vector>

using namespace std;

int main() {
	vector<int> myVector = { 1,9,44,422,676,78 };
	vector<int>::iterator it;
	it = myVector.begin();	//этот метод даёт доступ к первому элементу вектора
	*it = 1000;				//поменяется
	vector<int>::const_iterator it1;
	it1 = myVector.cbegin();
	//*it1 = 100000;		//нельзя, так как константный
	for (vector<int>::reverse_iterator i = myVector.rbegin(); i != myVector.rend(); i++)	//от конца к началу
		cout << *i << endl;
	advance(it, 3);			//не все итераторы можно будет смещать (не все итераторы произвольного доступа)
	cout << endl << *it << endl;
	system("pause");
	return 0;
}