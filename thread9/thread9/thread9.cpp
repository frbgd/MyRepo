//mutex
#include<iostream>
#include<mutex>
#include<thread>
#include"SimpleTimer.h"

using namespace std;

mutex mtx;

void Print(char ch) {
	this_thread::sleep_for(chrono::milliseconds(2000));
	mtx.lock();
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++) {
			cout << ch;
			this_thread::sleep_for(chrono::milliseconds(20));
		}
		cout << endl;
	}
	cout << endl;
	mtx.unlock();
	this_thread::sleep_for(chrono::milliseconds(2000));
}

int main()
{
	SimpleTimer timer;
	thread t1(Print, '*');
	thread t2(Print, '#');
	thread t3(Print, '@');
	t1.join();
	t2.join();
	t3.join();
	timer.~SimpleTimer();
	system("pause");
	return 0;
}