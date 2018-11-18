#include <cstdlib>
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

#define STORAGE_MIN 10
#define STORAGE_MAX 20

using namespace std;

int storage = STORAGE_MIN;

mutex globalMutex;
condition_variable condition;

/* Функция потока потребителя */
void consumer()
{
	cout << "[CONSUMER] thread started" << endl;
	int toConsume = 0;

	while (true)
	{
		unique_lock<mutex> lock(globalMutex);
		/* Если значение общей переменной меньше максимального,
		 * то поток входит в состояние ожидания сигнала о достижении
		 * максимума */
		if (storage < STORAGE_MAX)
		{
			condition.wait(lock); // Атомарно _отпускает мьютекс_ и сразу же блокирует поток
			toConsume = storage - STORAGE_MIN;
			cout << "[CONSUMER] storage is maximum, consuming "
				<< toConsume << endl;
		}
		/* "Потребление" допустимого объема из значения общей
		 * переменной */
		storage -= toConsume;
		cout << "[CONSUMER] storage = " << storage << endl;
	}
}

/* Функция потока производителя */
void producer()
{
	cout << "[PRODUCER] thread started" << endl;

	while (true)
	{
		this_thread::sleep_for(chrono::milliseconds(200));

		unique_lock<mutex> lock(globalMutex);
		++storage;
		cout << "[PRODUCER] storage = " << storage << endl;
		/* Если значение общей переменной достигло или превысило
		 * максимум, поток потребитель уведомляется об этом */
		if (storage >= STORAGE_MAX)
		{
			cout << "[PRODUCER] storage maximum" << endl;
			condition.notify_one();
		}
	}
}

int main(int argc, char *argv[])
{
	thread thProducer(producer);
	thread thConsumer(consumer);

	thProducer.join();
	thConsumer.join();

	return 0;
}