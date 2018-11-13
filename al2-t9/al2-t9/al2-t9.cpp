#include<iostream>
using namespace std;

class Square {
	double s;
public:
	Square(double a) { s = a; }
	double SSquare() { return s * s; }
};

int main()
{
	double a;
	cout << "Enter side: "; cin >> a;
	Square A(a);
	cout << "Square of the square is " << A.SSquare() << endl;
	system("pause");
	return 0;
}