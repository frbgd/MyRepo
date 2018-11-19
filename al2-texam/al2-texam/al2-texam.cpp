#include<string>
#include<iostream>

using namespace std;

class Student {
	char FIO[256];
	double score[4];
public:
	Student(char *a, double *b) {
		strcpy_s(FIO, a);
		for (int i = 0; i < 4; i++)
			score[i] = b[i];
	}
	double ScoreAverage() {
		return (score[0] + score[1] + score[2] + score[3]) / 4;
	}
	void PrintS() {
		cout << "Student: " << FIO << "\taverage score = " << ScoreAverage() << endl;
	}
};

int main() {
	char A1[] = "Kucheryavenko Aleksey Pavlovich";
	double A2[4] = { 5,4,3,3 };
	Student A(A1, A2);
	A.PrintS();
	system("pause");
	return 0;
}