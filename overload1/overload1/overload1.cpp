#include<iostream>
using namespace std;

class Class {
	int a;
public:
	Class(int a = 1) { this->a = a; }
	void Ch_a(int ch) { a = ch; }
	friend void operator ++(Class &C, int);
	int Get_a() { return a; }
};

Class & operator ++(Class &C) { 
	int ch = C.Get_a(); ++ch;
	C.Ch_a(ch);
	return C; 
}
void operator ++(Class &C, int) { C.a++; }

int main()
{
	Class A;
	cout << A.Get_a() << endl;
	cout << (++A).Get_a() << endl;
	A++;
	cout << A.Get_a() << endl;
	system("pause");
	return 0;
}