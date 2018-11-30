#include <iostream>

#include <set>  // заголовочный файл множест и мультимножеств
#include <iterator>
#include <cstdlib>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	//srand(time(NULL));
	set<int> mySet; // объявили пустое множество

	// добавляем элементы в множество
	for (int i = 0; i < 10; i++) {
		mySet.insert(rand() % 100);
	}

	cout << "Элементы множества: ";
	copy(mySet.begin(), mySet.end(), ostream_iterator<int>(cout, " "));

	int del = 0;
	cout << "\nКакой элемент удалить? ";
	cin >> del;

	cout << "Элемент " << *mySet.find(del) << " - удален!" << endl;
	mySet.erase(del);

	int add = 0;
	cout << "Какой элемент добавить? ";
	cin >> add;

	cout << "Новый элемент добавлен на место старого - " << *mySet.lower_bound(add) << endl;
	mySet.insert(add);

	cout << "Мы удалили элемент " << del << " и добавили " << add << ".\nВот что получилось: " << endl;
	copy(mySet.begin(), mySet.end(), ostream_iterator<int>(cout, " "));
	system("pause");
	return 0;
}