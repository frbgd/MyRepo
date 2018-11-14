#include<iostream>
using namespace std;

class Complex {
	double re;
	double im;
public:
	Complex(double a = 0, double b = 0) { re = a; im = b; }
	Complex & operator =(Complex &C) {
		if (&C == this)
			return *this;
		re = C.re;
		im = C.im;
		return *this;
	}
	void printC() { cout << re << " + " << im << "i" << endl; }
	friend Complex & operator *(Complex &C1, Complex &C2);
	Complex & operator *(double a) {
		re *= a;
		im *= a;
		return *this;
	}
	double Getre() { return re; }
	double Getim() { return im; }
};

Complex & operator *(Complex &C1, Complex &C2) {
	Complex *C = new Complex;
	C->im = C1.re * C2.im + C1.im * C2.re;
	C->re = C1.re * C2.re - C1.im * C2.im;
	return *C;
}

class CComplex : public Complex {
	double jim;
public:
	CComplex(double a = 0, double b = 0, double c = 0) : Complex(a,b) { jim = c; }
	CComplex & operator =(CComplex &C) {
		if (&C == this)
			return *this;
		jim = C.jim;
		Complex::operator =(C);
		return *this;
	}
	CComplex & operator =(Complex &C) {
		Complex::operator =(C);
		return *this;
	}
	void printC(){ cout << Complex::Getre() << " + " << Complex::Getim() << "i + " << jim << "j" << endl; }
};

int main()
{
	Complex A, B(2, 3), C(-1.77);
	A.printC();
	B.printC();
	C.printC();
	A = B;
	A.printC();
	A = A * B;
	A.printC();
	A = A * 0;
	A.printC();
	CComplex D(1,0,2), E;
	D.printC();
	E = C;
	E.printC();
	D = E;
	D.printC();
	system("pause");
	return 0;
}