//взаимная блокировка deadlock
#include<iostream>
#include<mutex>
#include<thread>
#include"SimpleTimer.h"

using namespace std;

mutex mtx1;
mutex mtx2;

void Print() {
	//mtx2.lock();
	mtx1.lock();
	this_thread::sleep_for(chrono::milliseconds(1));
	//mtx1.lock();
	mtx2.lock();
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++) {
			cout << '*';
			this_thread::sleep_for(chrono::milliseconds(10));
		}
		cout << endl;
	}
	cout << endl;
	mtx1.unlock();
	mtx2.unlock();
}

void Print2() {
	mtx1.lock();
	this_thread::sleep_for(chrono::milliseconds(1));
	mtx2.lock();
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++) {
			cout << '#';
			this_thread::sleep_for(chrono::milliseconds(10));
		}
		cout << endl;
	}
	cout << endl;
	mtx1.unlock();
	mtx2.unlock();
}

int main()
{
	SimpleTimer timer;
	thread t1(Print);
	thread t2(Print2);
	t1.join();
	t2.join();
	timer.~SimpleTimer();
	system("pause");
	return 0;
}