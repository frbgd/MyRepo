#include<iostream>
using namespace std;

class Complex {
	double re, im;
	public:
	Complex() { re = 0; im = 0; }
	Complex(double a, double b) { re = a; im = b; }
	void Get_str() { cout << re << " + " << im << "i" << endl; }
	Complex & operator =(Complex &C) {
		re = C.re;
		im = C.im;
		return *this;
	}
	friend Complex & operator +(Complex &C1, Complex &C2);
	friend Complex & operator -(Complex &C1, Complex &C2);
	friend Complex & operator *(Complex &C1, Complex &C2);
};

Complex & operator +(Complex &C1, Complex &C2) {
	Complex *C = new Complex();
	C->im = C1.im + C2.im;
	C->re = C1.re + C2.re;
	return *C;
}

Complex & operator -(Complex &C1, Complex &C2) {
	Complex *C = new Complex();
	C->im = C1.im - C2.im;
	C->re = C1.re - C2.re;
	return *C;
}

Complex & operator *(Complex &C1, Complex &C2) {
	Complex *C = new Complex;
	C->im = C1.re * C2.im + C1.im * C2.re;
	C->re = C1.re * C2.re - C1.im * C2.im;
	return *C;
}

int main()
{
	Complex i1(1, 1), i2(2, 3), i3;
	i1.Get_str();
	i2.Get_str();
	i3 = i1 + i2;
	i3.Get_str();
	i3 = i1 - i2;
	i3.Get_str();
	i3 = i1 * i2;
	i3.Get_str();
	system("pause");
	return 0;
}