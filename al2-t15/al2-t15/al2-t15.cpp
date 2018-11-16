#include<math.h>
#define _USE_MATH_DEFINES
#include<iostream>
using namespace std;

class circle {
protected:
	double r;
public:
	circle(double a = 2) { r = a; }
	virtual double Calculation() { return M_PI * r * r; }
	void Print() { cout << endl << "r=" << r << " square/volume=" << Calculation(); }
};

class ball : public circle {
	double z;
public:
	ball(double a = 2) : circle(a) { ; }
	double Calculation() { return 4 * M_PI * r * r * r / 3; }
};

int main()
{
	circle A;
	ball B;
	circle *ptr;
	ptr = &A;
	ptr->Print();
	ptr = &B;
	ptr->Print();
	cout << endl;
	system("pause");
	return 0;
}