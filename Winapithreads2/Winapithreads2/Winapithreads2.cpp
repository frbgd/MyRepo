#include<windows.h>
#include<iostream>
#include <time.h>  

using namespace std;

DWORD WINAPI Thread1Proc(LPVOID lpParam) {
	int* a = (int*)lpParam;
	for (int j = 0; j < 10000; j++) {
		for (int i = 0; i < 50000; i++)a[i]++;
	}
	return 0;
}

DWORD WINAPI Thread2Proc(LPVOID lpParam) {
	int* a = (int*)lpParam;
	for (int j = 0; j < 10000; j++) {
		for (int i = 50000; i < 100000; i++)a[i]++;
	}
	return 0;
}

int main() {
	clock_t time = clock();
	int a[100000] = { 0 };
	HANDLE th1 = CreateThread(NULL, 0, Thread1Proc, LPVOID(a), 0, NULL);
	HANDLE th2 = CreateThread(NULL, 0, Thread2Proc, LPVOID(a), 0, NULL);
	WaitForSingleObject(th1, INFINITE);
	WaitForSingleObject(th2, INFINITE);
	time = clock() - time;
	int ms = time * 1000 / CLOCKS_PER_SEC;
	cout << "time: " << ms << endl;
	system("pause");
	return 0;
}