//алгоритм сортировки
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
	//sort(people.begin(), people.end()); //так работать не будет - для нашего класса не перегружены операторы сравнения, можно перегрузить их, можно испльзовать предикат лучше анонимный
	sort(people.begin(), people.end(), [](const Person &p1, const Person &p2) {
		return p1.name < p2.name;
	});
	for (auto element : people)
		cout << element.name << '\t' << element.score << endl;
	cout << endl;
	sort(people.begin(), people.end(), [](const Person &p1, const Person &p2) {
		return p1.score < p2.score;
	});
	for (auto element : people)
		cout << element.name << '\t' << element.score << endl;
	system("pause");
	return 0;
}