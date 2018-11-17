//взаимное исключение

#include <windows.h>
#include <iostream>
#include <time.h>

#define COUNT_THREADS 4
#define ITERATIONS 100

//Mutex(мьютекс) - mutual exception(объект взаимного исключения)
DWORD iVal = 0;
HANDLE hMutex = NULL;

VOID Mutex(VOID);
DWORD WINAPI Func0(LPVOID lpParam);
DWORD WINAPI Func1(LPVOID lpParam);
DWORD WINAPI Func2(LPVOID lpParam);
DWORD WINAPI Func3(LPVOID lpParam);

int main(int argc, char* args[])
{
	srand((unsigned)time(0));
	Mutex();
	system("pause");
	return 0;
}

VOID Mutex(VOID)
{
	HANDLE globalThreads[COUNT_THREADS] = { 0 };
	hMutex = CreateMutex(NULL, FALSE, "Samename");
	globalThreads[0] = CreateThread(NULL, 0, Func0, NULL, NULL, 0);
	globalThreads[1] = CreateThread(NULL, 0, Func1, NULL, NULL, 0);
	globalThreads[2] = CreateThread(NULL, 0, Func2, NULL, NULL, 0);
	globalThreads[3] = CreateThread(NULL, 0, Func3, NULL, NULL, 0);

	WaitForMultipleObjects(COUNT_THREADS, globalThreads, TRUE, INFINITE);

	if (globalThreads[0] != INVALID_HANDLE_VALUE)
		CloseHandle(globalThreads[0]);
	if (globalThreads[1] != INVALID_HANDLE_VALUE)
		CloseHandle(globalThreads[1]);
	if (globalThreads[2] != INVALID_HANDLE_VALUE)
		CloseHandle(globalThreads[2]);
	if (globalThreads[3] != INVALID_HANDLE_VALUE)
		CloseHandle(globalThreads[3]);
}

DWORD WINAPI Func0(LPVOID lpParam)
{
	while (iVal < 100)
	{
		WaitForSingleObject(hMutex, INFINITE);
		std::wcout << L"Func0: " << iVal++ << std::endl;
		ReleaseMutex(hMutex);
	}
	ExitThread(0);
}
DWORD WINAPI Func1(LPVOID lpParam)
{
	while (iVal < 100)
	{
		WaitForSingleObject(hMutex, INFINITE);
		std::wcout << L"Func1: " << iVal++ << std::endl;
		ReleaseMutex(hMutex);
	}
	ExitThread(0);
}
DWORD WINAPI Func2(LPVOID lpParam)
{
	while (iVal < 100)
	{
		WaitForSingleObject(hMutex, INFINITE);
		std::wcout << L"Func2: " << iVal++ << std::endl;
		ReleaseMutex(hMutex);
	}
	ExitThread(0);
}
DWORD WINAPI Func3(LPVOID lpParam)
{
	while (iVal < 100)
	{
		WaitForSingleObject(hMutex, INFINITE);
		std::wcout << L"Func3: " << iVal++ << std::endl;
		ReleaseMutex(hMutex);
	}
	ExitThread(0);
}