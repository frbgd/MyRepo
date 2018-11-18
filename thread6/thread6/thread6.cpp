//С++ потоки и методы класса | С++ метод класса в потоке | Многопоточное программирование
#include<iostream>
#include<thread>
#include<chrono>

using namespace std;

class MyClass {
public:
	void DoWork() {
		this_thread::sleep_for(chrono::milliseconds(1000));
		cout << "Thread ID = " << this_thread::get_id() << " =================\tDoWork started\t==================\n";
		this_thread::sleep_for(chrono::milliseconds(4000));
		cout << "Thread ID = " << this_thread::get_id() << " =================\tDoWork stopped\t==================\n";
	}
	void DoWork2(int a) {
		this_thread::sleep_for(chrono::milliseconds(3000));
		cout << "Thread ID = " << this_thread::get_id() << " =================\tDoWork2 started\t==================\n";
		this_thread::sleep_for(chrono::milliseconds(3000));
		cout << "DoWork2 value of parameter\t" << a << endl;
		cout << "Thread ID = " << this_thread::get_id() << " =================\tDoWork2 stopped\t==================\n";
	}
	int Sum(int a, int b) {
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "Thread ID = " << this_thread::get_id() << " =================\tSum started\t==================\n";
		this_thread::sleep_for(chrono::milliseconds(5000));
		cout << "Thread ID = " << this_thread::get_id() << " =================\tSum stopped\t==================\n";
		return a + b;
	}
};
int main() {
	MyClass m;
	int result;
	
	thread t1([&]() {	//лямюда-функция будет работать со всемы переменными
		result = m.Sum(2, 5);
	});
	thread t2(&MyClass::DoWork, m);
	thread t3(&MyClass::DoWork2, m, 5);
	for (size_t i = 0; i < 10; i++) {
		cout << "Thread ID = " << this_thread::get_id() << "\tmain\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}
	t1.join();
	t2.join();
	t3.join();
	cout << "Result\t" << result << endl;
	system("pause");
	return 0;
}