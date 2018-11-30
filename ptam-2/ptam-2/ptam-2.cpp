#include <iostream>
#include <map>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	map <int, int>  street; // ������� ������
	int n;

	cout << "������� ���������� ����� �� �����: "; cin >> n;      // ��������� ���������� 
	cout << "������� ��� � ������� � ��� ����� �����: " << endl;  // ����� 

	for (int i = 0; i < n; i++) {
		int house, people;
		cout << i << ") ��� ";
		cin >> house; cin >> people;  // ��������� ��������� ��������
		street.insert(make_pair(house, people));
	}

	int q;
	cout << endl << "������� ���������� ��������: ";
	cin >> q;

	for (int i = 0; i < q; i++) {
		cout << i << ") ";
		int a; cin >> a;

		if (a == 0) { // ������ ������ ��������
			int house;
			cout << "������� ����� ����: "; cin >> house;
			if (street.count(house)) {
				cout << "���������� �����: " <<
					street[house] << endl;
			}
			else {
				cout << "������ ���� �� ����������! " << endl;
			}
		}
		if (a == 1) { // ������ ������ ��������
			int deleter;
			cout << "����� ��� �������: ";  cin >> deleter;
			if (street.find(deleter) == street.end()) {
				cout << "��� ��� � ������, �������� ��� �������� :)";
			}
			else {
				street.erase(street.find(deleter));
				cout << "������� ������! " << endl;
			}
		}

		if (a == 2) { // ������ ������� ��������
			int house, people;
			cout << "����� ��� ��������: "; cin >> house;
			cout << "����� ���������� ����� ��� ���������: "; cin >> people;
			street[house] = people;
		}
	}
	cout << endl;
	system("pause");
	return 0;
}