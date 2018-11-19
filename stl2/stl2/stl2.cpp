//vector
#include <iostream>
#include<vector>

using namespace std;

int main() {
	vector<int> myVector = { 2,44,77,9 };
	myVector.push_back(2);
	myVector.push_back(44);
	myVector.push_back(77);
	myVector.push_back(9);
	cout << "Vector size = " << myVector.size() << endl;
	cout << "Vector capacity = " << myVector.capacity() << endl;
	myVector.reserve(100);
	cout << "Vector capacity = " << myVector.capacity() << endl;
	myVector.shrink_to_fit();
	cout << "Vector capacity = " << myVector.capacity() << endl;
	vector<int> myVector1(10, 55);
	for (int i = 0; i < myVector1.size(); i++)
		cout << myVector1[i] << endl;
	myVector1.resize(12);
	for (int i = 0; i < myVector1.size(); i++)
		cout << myVector1[i] << endl;
	cout << endl << myVector1.empty() << endl;
	system("pause");
	return 0;
}