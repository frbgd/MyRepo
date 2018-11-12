#include<math.h>
#define _USE_MATH_DEFINES
#include<iostream>
using namespace std;

class angle {
	float count;
public:
	angle(int a) {
		int degrees = a % 360;
		count = degrees * M_PI / 180;
	}
	float cosa() { return cos(count); }
};

int main()
{
	int a;
	cout << "Enter an angle (degrees): "; cin >> a;
	angle A(a);
	float b = A.cosa();
	cout << "cos(" << a << ") = " << b << endl;
	system("pause");
	return 0;
}