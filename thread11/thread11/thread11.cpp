//lock_guard
#include<iostream>
#include<mutex>
#include<thread>

using namespace std;

mutex mtx;

void Print(char ch) {
	this_thread::sleep_for(chrono::milliseconds(2000));
	{									//ограничили область видимости, чтобы обеспечить асинхронное выполнение последней sleep_for в этой функции
		lock_guard<mutex> guard(mtx); //захват mutex'а в конструкторе, отпуск - в деструкторе
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 10; j++) {
				cout << ch;
				this_thread::sleep_for(chrono::milliseconds(10));
			}
			cout << endl;
		}
		cout << endl;
	}									//ограничили область видимости, чтобы обеспечить асинхронное выполнение последней sleep_for в этой функци
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