#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
	string path = "2.txt";

	ifstream fin;
	fin.exceptions(ifstream::badbit | ifstream::failbit);

	try
	{
		cout << "Trying to open file\n";
		fin.open(path);
		cout << "File is open\n";
	}

	catch (const ifstream::failure& ex)
	{
		cout << ex.what() << endl;
		cout << ex.code() << endl;
		cout << "Error file opening!\n";
	}
	system("pause");
	return 0;
}