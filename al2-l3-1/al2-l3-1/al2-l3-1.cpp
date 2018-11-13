#include<iostream>
using namespace std;

class Vector {
	double *p;
	int size;
public:
	Vector() { p = 0; size = 0; }
	Vector(double* arr, int n) {
		size = n;
		p = new double[n];
		for (int i = 0; i < size; i++)
			p[i] = arr[i];
	}
	~Vector() { if (size > 0) delete[] p; }
	double operator [] (int index) {
			return p[index];
	}
	Vector & operator =(Vector &V) {
		size = V.size;
		p = new double[size];
		for (int i = 0; i < V.size; i++)
			p[i] = V.p[i];
		return *this;
	}
	Vector & operator *(double b) {
		for (int i = 0; i < size; i++)
			p[i] *= b;
		return *this;
	}
};

int main() {
	double arr1[] = { 1, 2, 3, 4, 5, 6, 7 };
	Vector A(arr1, 7);
	cout << A[5] << endl;
	Vector B;
	B = A;
	cout << B[5] << endl;
	A * 2; B * 5;
	cout << A[5] << endl << B[5] << endl;
	system("pause");
	return 0;
}