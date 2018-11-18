//async(), future<>
#include<iostream>
#include<windows.h>
#include<future>

using namespace std;

void FreeWheel(const char *message) {
	while (true) {
		Sleep(500);
		cout << message << endl;
	}
}

int main()
{
	std::future<void> à = async(FreeWheel, "async rocks!!!");
	system("pause");
	return 0;
}