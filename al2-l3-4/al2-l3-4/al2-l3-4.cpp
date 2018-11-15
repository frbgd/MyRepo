#include <iostream>
#include <conio.h>
using namespace std;

class Student
{
	char FIO[256];
	int five, four, three;
public:
	Student(char* a, int b, int c, int d)
	{
		strcpy_s(FIO, a);
		five = b; four = c; three = d;
	}
	virtual void print() { cout << endl << FIO << endl << five << " " << four << " " << three; }
};

class Student_iu8 : public Student {
	int tail;
public:
	Student_iu8(char* a, int b, int c, int d, int e) : Student(a, b, c, d) { tail = e; }
	void print() { 
		Student::print();
		cout << " " << tail;
	}
};

int main()
{
	char a[] = "Stipa";
	char b[] = "Basos";
	Student botan(a, 5, 1, 0);
	Student_iu8 macho(b, 0, 0, 1, 5);
	cout.clear();
	Student *pp;
	pp = &botan;
	pp->print();
	pp = &macho;
	pp->print();
	cout << endl;
	system("pause");
	return 0;
}
