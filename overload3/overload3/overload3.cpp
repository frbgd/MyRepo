#include<iostream>
using namespace std;

class Vector {
	int *p;
	int size;
public:
	Vector() { p = 0; size = 0; }
	Vector(int* arr, int n) {
		size = n;
		p = new int[size];
		for (int i = 0; i < size; i++)
			p[i] = arr[i];
	}
	~Vector() { if (size > 0) delete[] p; }
	Vector & operator =(Vector &V) {
		size = V.size;
		p = new int[size];
		for (int i = 0; i < size; i++)
			p[i] = V.p[i];
		V.p = 0;
		V.size = 0;
		return *this;
	}
	void PrintV() {
		for (int i = 0; i < size; i++)
			cout << p[i] << " ";
		cout << endl;
	}
};

int main() {
	int array[] = { 1, 2, 3, 4, 5 };
	Vector A(array, 5);
	Vector B;
	cout << "Vector A: ";
	A.PrintV();
	cout << "Vector B: ";
	B.PrintV();
	cout << "Vector A moved to B" << endl;
	B = A;
	cout << "Vector A: ";
	A.PrintV();
	cout << "Vector B: ";
	B.PrintV();
	system("pause");
	return 0;
}