#include<iostream>
using namespace std;

class rectangle {
protected:
	double a, b;
public:
	rectangle(double a = 1, double b = 2) { this->a = a; this->b = b; }
	double Calculation() { return a * b; }
	void Print() { cout << endl << "a=" << a << " b=" << b << " Square=" << Calculation(); }
};

class cuboid : public rectangle {
	double h;
public:
	cuboid(double a = 3, double b = 4, double c = 5) : rectangle(a, b) { h = c; }
	double Calculation() { return rectangle::Calculation() * h; }
	void Print() { cout << endl << "a=" << a << " b=" << b << " h=" << h << " Volume=" << Calculation(); }
};

int main()
{
	rectangle A;
	cuboid B;
	rectangle *pr = &A;
	pr->Print();
	pr = &B;
	pr->Print();
	cuboid *pc = &B;
	pc->Print();
	cout << endl;
	system("pause");
	return 0;
}