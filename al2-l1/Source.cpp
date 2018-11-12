#include<iostream>
using namespace std;

class Man
{
	char fio[128];
	double chas;
public:
	Man(char mar[], double r)
	{
		strcpy_s(fio, mar);
		chas = r;
	}
	double getZP(double zp_in_hour)
	{
		return chas * zp_in_hour;
	}
	void print()
	{
		cout << endl << "FIO: " << fio << endl << "hours=" << chas << endl;
	}
};

int main()
{
	unsigned int n; cout << "n= "; cin >> n;
	double zp_in_hour; cout << "zp in hour = "; cin >> zp_in_hour;
	double ZP = 0, r;
	char FIO[128];
	Man **ppA = new Man*[n];
	for (unsigned int i = 0; i < n; ++i)
	{
		cout << "Object N=" << (i + 1) << ":" << endl << "FIO: ";
		cin >> FIO;
		cout << "hours="; cin >> r;
		cout << endl;
		ppA[i] = new Man(FIO, r);
	}
	for (unsigned int i = 0; i < n; ++i)
	{
		ppA[i]->print();
		cout << "zp=" << ppA[i]->getZP(zp_in_hour) << endl;
		ZP += ppA[i]->getZP(zp_in_hour);
	}
	cout << endl << "Sum=" << ZP << endl;
	for (unsigned int i = 0; i < n; ++i) delete ppA[i];
	delete[] ppA;
	system("pause");
	return 0;
}