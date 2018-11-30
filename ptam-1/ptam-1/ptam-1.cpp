#include <iostream>

#include <set>  // ������������ ���� ������� � ��������������
#include <iterator>
#include <cstdlib>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	//srand(time(NULL));
	set<int> mySet; // �������� ������ ���������

	// ��������� �������� � ���������
	for (int i = 0; i < 10; i++) {
		mySet.insert(rand() % 100);
	}

	cout << "�������� ���������: ";
	copy(mySet.begin(), mySet.end(), ostream_iterator<int>(cout, " "));

	int del = 0;
	cout << "\n����� ������� �������? ";
	cin >> del;

	cout << "������� " << *mySet.find(del) << " - ������!" << endl;
	mySet.erase(del);

	int add = 0;
	cout << "����� ������� ��������? ";
	cin >> add;

	cout << "����� ������� �������� �� ����� ������� - " << *mySet.lower_bound(add) << endl;
	mySet.insert(add);

	cout << "�� ������� ������� " << del << " � �������� " << add << ".\n��� ��� ����������: " << endl;
	copy(mySet.begin(), mySet.end(), ostream_iterator<int>(cout, " "));
	system("pause");
	return 0;
}