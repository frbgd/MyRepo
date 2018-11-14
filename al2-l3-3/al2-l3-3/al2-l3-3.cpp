#include<iostream>
using namespace std;

class point {
	double x, y;
public:
	point(double a, double b) { x = a; y = b; }
	virtual void print() { cout << "\nx=" << x << " y=" << y; }
};

class point3d : public point {
	double z;
public:
	point3d(double a, double b, double c) : point(a, b) { z = c; }
	void print()
	{
		point::print();
		cout << " z=" << z;
	}
};

int main()
{
	point p1(1, 2);
	point3d p3(3, 4, 5);
	point *pp;
	pp = &p1;
	pp->print();
	pp = &p3;
	pp->print();
	cout << endl;
	system("pause");
	return 0;
}