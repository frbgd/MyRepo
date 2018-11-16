#include<string.h>
#include<iostream>
using namespace std;

class car {
	char model[256];
	int maxs;
public:
	car(const char *a, int b) { strcpy_s(model, a); maxs = b; }
	virtual void Print() { cout << endl << "Model: " << model << ", Max speed = " << maxs; }
};

class truck :public car {
	double lc;
public:
	truck(const char *a, int b, double c) :car(a, b) { lc = c; }
	void Print() { car::Print(); cout << " Load capacity = " << lc; }
};

int main()
{
	car A("Ford", 120);
	truck B("Cargo", 80, 12);
	car *ptr;
	ptr = &A;
	ptr->Print();
	ptr = &B;
	ptr->Print();
	cout << endl;
	system("pause");
	return 0;
}