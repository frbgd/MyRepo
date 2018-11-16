#include<string.h>
#include<iostream>
using namespace std;

class employee {
	char FIO[256];
protected:
	double s;
public:
	employee(const char *a, double b) { strcpy_s(FIO, a); s = b; }
	void Print() { cout << endl << FIO << ' ' << s; }
};

class boss : public employee {
	double ss;
public:
	boss(const char *a, double b, double c) : employee(a, b) { ss = c; }
	void Print() { employee::Print(); cout << ' ' << s + ss; }
};

int main() {
	employee A("Zhora", 45000);
	boss B("Dima", 60000, 10000);
	employee *pe = &A;
	pe->Print();
	pe = &B;
	pe->Print();
	boss *pb = &B;
	pb->Print();
	cout << endl;
	system("pause");
	return 0;
}