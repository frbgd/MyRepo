//предикат
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Person {
	string name;
	double score;
public:
	Person(string name, double score) {
		this->name = name;
		this->score = score;
	}
	bool operator()(const Person &p) {		//предикат
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
	auto result = count_if(people.begin(), people.end(), people.front());	//алгоритм count_if считает что-либо в коллекции, метод front получает ссылку на первый элемент вектора
	cout << result << endl;													//первый элемент Person("Jim",181) передаётся в алгоритм в качестве предиката
	system("pause");
	return 0;
}