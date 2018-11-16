#include<iostream>
using namespace std;

class square {
protected:
	double s;
public:
	square(double a = 2) { s = a; }
	double Calculation() { return s * s; }
	void Print() { cout << endl << "s=" << s << " Square=" << Calculation(); }
};

class cube : public square {
public:
	cube(double a = 3) : square(a) { ; }
	double Calculation() { return square::Calculation() * s; }
	void Print() { cout << endl << "s=" << s << " Volume=" << Calculation(); }
};

int main()
{
	square A;
	cube B;
	A.Print();
	B.Print();
	cout << endl;
	system("pause");
	return 0;
}