#include<math.h>
#include<iostream>
using namespace std;

class number{
	double re;
public:
	number(double a = 1) { re = a; }
	virtual double Abs() { return re; }
	virtual void Print() { cout << endl << re << ' ' << Abs(); }
};

class complex :public number {
	double im;
public:
	complex(double a = 2, double b = 3) : number(a) { im = b; }
	double Abs() { return sqrt(pow(number::Abs(), 2) + pow(im, 2)); }
	void Print() { cout << endl << number::Abs() << '+' << im << "i " << Abs(); }
};

int main()
{
	number A;
	complex B;
	number *ptr;
	ptr = &A;
	ptr->Print();
	ptr = &B;
	ptr->Print();
	cout << endl;
	system("pause");
	return 0;
}