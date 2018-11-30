#include <iostream>
#include <map>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	map <int, int>  street; // создали журнал
	int n;

	cout << "¬ведите количество домов на улице: "; cin >> n;      // считываем количество 
	cout << "”кажите дом и сколько в нем живет людей: " << endl;  // домов 

	for (int i = 0; i < n; i++) {
		int house, people;
		cout << i << ") ƒом ";
		cin >> house; cin >> people;  // считываем введенные значени€
		street.insert(make_pair(house, people));
	}

	int q;
	cout << endl << "¬ведите количество операций: ";
	cin >> q;

	for (int i = 0; i < q; i++) {
		cout << i << ") ";
		int a; cin >> a;

		if (a == 0) { // начала первой операци€
			int house;
			cout << "”кажите номер дома: "; cin >> house;
			if (street.count(house)) {
				cout << " оличество людей: " <<
					street[house] << endl;
			}
			else {
				cout << "“акого дома не существует! " << endl;
			}
		}
		if (a == 1) { // начала второй операции
			int deleter;
			cout << " акой дом удалить: ";  cin >> deleter;
			if (street.find(deleter) == street.end()) {
				cout << "≈го нет в списке, возможно уже разрушен :)";
			}
			else {
				street.erase(street.find(deleter));
				cout << "Ёлемент удален! " << endl;
			}
		}

		if (a == 2) { // начала третьей операции
			int house, people;
			cout << " акой дом добавить: "; cin >> house;
			cout << " акое количество людей там проживает: "; cin >> people;
			street[house] = people;
		}
	}
	cout << endl;
	system("pause");
	return 0;
}