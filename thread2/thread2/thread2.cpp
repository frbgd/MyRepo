#include<iostream>
#include<thread>
#include<chrono>

using namespace std;

void DoWork(int a, int b, const char *msg) {
	cout << msg << endl;
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "=================\tDoWork started\t==================\n";
	this_thread::sleep_for(chrono::milliseconds(5000));
	cout << "a + b" << a + b << endl;
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "=================\tDoWork stopped\t==================\n";
}

int main() {
	thread th(DoWork, 1, 6, "Our work");
	for (size_t i = 0; true; i++) {
		cout << "Thread ID = " << this_thread::get_id() << "\tmain\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}
	th.join();
	return 0;
}