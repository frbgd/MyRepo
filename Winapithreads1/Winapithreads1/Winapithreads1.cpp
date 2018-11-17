#include<windows.h>
#include<iostream>

using namespace std;

DWORD WINAPI Thread1Proc(LPVOID lpParam) {
	for (int i = 0; i < 100; i++) {
		cout << "Th1 " << i << endl;
	}
	return 0;
}

DWORD WINAPI Thread2Proc(LPVOID lpParam) {
	for (int i = 0; i < 100; i++) {
		cout << "Th2 " << i << endl;
	}
	return 0;
}

int main() {
	HANDLE th1 = CreateThread(NULL, 0, Thread1Proc, NULL, CREATE_SUSPENDED, NULL);
	HANDLE th2 = CreateThread(NULL, 0, Thread2Proc, NULL, CREATE_SUSPENDED, NULL);
	ResumeThread(th1);
	ResumeThread(th2);
	WaitForSingleObject(th1, INFINITE);
	WaitForSingleObject(th2, INFINITE);
	system("pause");
	return 0;
}