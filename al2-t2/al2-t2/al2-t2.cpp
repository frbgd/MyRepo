#include<iostream>
using namespace std;

class integer {
	int count;
public:
	integer(int i) { count = i; }
	void printh(){
		cout << hex << count << endl;
	}
};

int main()
{
	int a;
	cout << "Enter integer: "; cin >> a;
	integer A(a);
	A.printh();
	system("pause");
	return 0;
}