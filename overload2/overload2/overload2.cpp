#include<iostream>
using namespace std;

class Class {
	int a;
public:
	Class(int a = 1) { this->a = a; }
	int Get_a() { return a; }
	bool operator >(Class &C) {
		if (a > C.a)
			return true;
		return false;
	}
	friend bool operator ==(Class &C1, Class &C2);
};

bool operator ==(Class &C1, Class &C2) {
	if (C1.a == C2.a)
		return true;
	return false;
}

bool operator <(Class &C1, Class &C2) {
	if (C1.Get_a() < C2.Get_a())
		return true;
	return false;
}

int main()
{
	Class A, B(2);
	cout << (A > B) << (B > A) << (A == B) << (A == A) << (A < B) << (B < A) << endl;
	system("pause");
	return 0;
}