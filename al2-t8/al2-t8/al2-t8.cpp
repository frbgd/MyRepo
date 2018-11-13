#include<math.h>
#define _USE_MATH_DEFINES
#include<iostream>
using namespace std;

class Circle {
	double r;
public:
	Circle(double a) { r = a; }
	double CLength() { return 2 * M_PI * r; }
};

int main()
{
	double a;
	cout << "Enter radius: "; cin >> a;
	Circle A(a);
	cout << "Length of the circle is " << A.CLength() << endl;
	system("pause");
	return 0;
}