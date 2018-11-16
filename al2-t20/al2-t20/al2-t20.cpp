#include <iostream>
using namespace std;

class square {
	double s;
public:
	square(double a = 2) { s = a; }
	double Perimeter() { return s * 4; }
	void Print() { cout << endl << s << ' ' << Perimeter(); }
};

class rectangle : public square {
	double s2;
public:
	rectangle(double a = 2, double b = 3) :square(a) { s2 = b; }
	double Perimeter() { return square::Perimeter() / 2 + 2 * s2; }
	void Print() { cout << endl << square::Perimeter() / 4 << ' ' << s2 << ' ' << Perimeter(); }
};

int main() {
	square A;
	rectangle B;
	square *ps = &A;
	ps->Print();
	ps = &B;
	ps->Print();
	rectangle *pr = &B;
	pr->Print();
	cout << endl;
	system("pause");
	return 0;
}