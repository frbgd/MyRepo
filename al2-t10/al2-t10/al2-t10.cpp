#include<iostream>
using namespace std;

class Square {
	double s;
public:
	Square(double a) { s = a; }
	double Perimeter() { return 4 * s; }
};

int main()
{
	double a;
	cout << "Enter a side: "; cin >> a;
	Square A(a);
	cout << "Perimeter of the square is " << A.Perimeter() << endl;;
	system("pause");
	return 0;
}