//async(), future<>
#include<iostream>
#include<windows.h>
#include<future>

using namespace std;

int Sum(int a, int b) {
	this_thread::sleep_for(chrono::milliseconds(1000));
	cout << "Thread ID = " << this_thread::get_id() << " =================\tSum started\t==================\n";
	this_thread::sleep_for(chrono::milliseconds(1000));
	cout << "Thread ID = " << this_thread::get_id() << " =================\tSum stopped\t==================\n";
	return a + b;
}

int main()
{
	int a = 2, b = 5;
	int result = 0;
	cout << "result = " << result << endl;
	auto à = async([&]() {
		result = Sum(a, b); 
	});
	cout << "Thread ID = " << this_thread::get_id() << " main is waiting for sum...\n";
	Sleep(2500);
	cout << "result = " << result << endl;
	system("pause");
	return 0;
}