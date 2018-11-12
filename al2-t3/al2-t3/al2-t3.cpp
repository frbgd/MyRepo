#include<iostream>
#include<conio.h>
using namespace std;

class symbol {
	char count;
public:
	symbol(char s) { count = s; }
	void printd() { cout << hex << int(count) << endl; }
};

int main()
{
	char s;
	cout << "Enter a symbol: "; s = _getche(); cout << endl;
	symbol A(s);
	A.printd();
	system("pause");
	return 0;
}