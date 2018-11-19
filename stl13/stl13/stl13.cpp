//алгоритмы поиска
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Person {
public:
	string name;
	double score;
	Person(string name, double score) {
		this->name = name;
		this->score = score;
	}
	bool operator()(const Person &p) {
		return p.score > 180;
	}
};

int main() {
	vector<Person> people{
		Person("Jim", 181),
		Person("Jane", 30),
		Person("Dick", 179),
		Person("Bob", 200),
		Person("Duck", 198),
		Person("Alyosha", 181),
		Person("Jack",50),
		Person("Michael", 150),
	};
	auto result = find_if(people.begin(), people.end(), [](const Person &p) {
		return p.name == "Bob";
	});
	if (result == people.end()) {
		cout << "-\n";
	}
	else {				//else result == founded element
		cout << "+\n";
	}
	auto result1 = find_if(people.begin(), people.end(), [](const Person &p) {
		return p.score < 30;
	});
	if (result1 == people.end()) {
		cout << "-\n";
	}
	else {
		cout << "+\n";
	}
	system("pause");
	return 0;
}