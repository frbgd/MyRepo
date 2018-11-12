#include<iostream>
using namespace std;

class integer {
	int count;
public:
	integer(int i) { count = i; }
	int parity() {
		if (count % 2 == 0)
			return 1;
		else
			return 0;
	}
};

int main()
{
	int a;
	cout << "Enter integer: "; cin >> a;
	integer A(a);
	int b = A.parity();
	b == 1 ? cout << a << " is even" << endl : cout << a << " is odd" << endl;
	system("pause");
	return 0;
}