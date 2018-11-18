//unique_lock mutex | unique_lock vs lock_guard
#include<iostream>
#include<mutex>
#include<thread>

using namespace std;

mutex mtx;

void Print(char ch) {
	unique_lock<mutex> ul(mtx, defer_lock);				//способ с конструктором и деструктором, как у guard_lock, тоже работает
	this_thread::sleep_for(chrono::milliseconds(2000));
	ul.lock();
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++) {
			cout << ch;
			this_thread::sleep_for(chrono::milliseconds(10));
		}
		cout << endl;
	}
	cout << endl;
	ul.unlock();
	this_thread::sleep_for(chrono::milliseconds(2000));
}

int main()
{
	thread t1(Print, '*');
	thread t2(Print, '#');
	thread t3(Print, '@');
	t1.join();
	t2.join();
	t3.join();
	system("pause");
	return 0;
}