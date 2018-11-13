#include<iostream>
using namespace std;

class Class {
	int a;
public:
	Class(int a = 1) { this->a = a; }
	Class & operator ++() { ++a; return *this; }
	void operator ++(int) { a++; }
	int Get_a() { return a; }
};

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