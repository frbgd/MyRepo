#include<iostream>
#include<thread>
#include<chrono>

using namespace std;

int Sum(int a, int b) {
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "Thread ID = " << this_thread::get_id() << " =================\tSum started\t==================\n";
	this_thread::sleep_for(chrono::milliseconds(5000));
	cout << "Thread ID = " << this_thread::get_id() << " =================\tSum stopped\t==================\n";
	return a + b;
}

int main() {

	int result;
	thread t([&result]() {result = Sum(2, 5); });
	for (size_t i = 0; i < 10; i++) {
		cout << "Thread ID = " << this_thread::get_id() << "\tmain\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}
	t.join();
	cout << "Sum result: " << result << endl;
	system("pause");
	return 0;
} 