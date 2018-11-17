#include<windows.h>
#include<iostream>

using namespace std;

CRITICAL_SECTION section;

DWORD WINAPI Thread1Proc(LPVOID lpParam) {
	for (int i = 0; i < 100; i++) {
		if (TryEnterCriticalSection(&section)) { //когда try, то некторые операции пропускаются, потому что в это время критическая секция у другого потока
			cout << "Th1 " << i << endl;		//если убрать sleep'ы, то везде первый поток будет захватывать критическую секцию первым
			LeaveCriticalSection(&section);
		}
		Sleep(1000);
	}
	return 0;
}

DWORD WINAPI Thread2Proc(LPVOID lpParam) {
	for (int i = 0; i < 100; i++) {
		if (TryEnterCriticalSection(&section)) {
			cout << "Th2 " << i << endl;
			LeaveCriticalSection(&section);
		}
		Sleep(1000);
	}
	return 0;
}

int main() {
	InitializeCriticalSection(&section);
	HANDLE th1 = CreateThread(NULL, 0, Thread1Proc, NULL, CREATE_SUSPENDED, NULL);
	HANDLE th2 = CreateThread(NULL, 0, Thread2Proc, NULL, CREATE_SUSPENDED, NULL);
	ResumeThread(th1);
	ResumeThread(th2);
	WaitForSingleObject(th1, INFINITE);
	WaitForSingleObject(th2, INFINITE);
	DeleteCriticalSection(&section);
	system("pause");
	return 0;
}