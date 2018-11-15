#include<math.h>
#include<iostream>
using namespace std;

class vector {
protected:
	double x, y;
public:
	vector(double a, double b) { x = a; y = b; }
	virtual double Len_v() { return sqrt(x * x + y * y); }
	virtual void Print_v() { cout << endl << "len=" << Len_v() << " x=" << x << " y=" << y; }
};

class vector_3d : public vector {
	double z;
public:
	vector_3d(double a, double b, double c) : vector(a, b) { z = c; }
	double Len_v() { return sqrt(x * x + y * y + z * z); }
	void Print_v() { vector::Print_v(); cout << " z=" << z; }
};

int main()
{
	vector A(1, 2);
	vector_3d B(3, 4, 5);
	vector *pv;
	pv = &A;
	pv->Print_v();
	pv = &B;
	pv->Print_v();
	cout << endl;
	system("pause");
	return 0;
}