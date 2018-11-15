#include <iostream>
using namespace std;

class point {
protected:
	double x, y;
public:
	point(double a = 0, double b = 0) { x = a; y = b; }
	virtual void Print_p() { cout << endl << "x=" << x << " y=" << y; }
};

class point_3d : public point{
	double z;
public:
	point_3d(double a, double b, double c) : point(a, b) { z = c; }
	void Print_p() {
		point::Print_p();
		cout << " z=" << z;
	}
};
int main()
{
	point A(1, 2);
	point_3d B(3, 4, 5);
	point *pp;
	pp = &A;
	pp->Print_p();
	pp = &B;
	pp->Print_p();
	cout << endl;
	system("pause");
	return 0;
}