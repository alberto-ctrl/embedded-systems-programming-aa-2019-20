// Example code for using condition variables.
// The main thread creates three threads:
// - 2 of these threads increment a "count" variable
// - 1 thread watches the value of "count"
// When "count" reaches a predefined "count_limit", 
// the waiting thread is signaled by one of the incrementing threads.

#include <iostream>
using std::cout;
using std::endl;
#include <thread>
using std::thread;
#include <mutex>
using std::unique_lock;
using std::mutex;
#include <condition_variable>
using std::condition_variable;

// SHARED VARIABLES and CONSTANT
const int count_limit{1200};
const int t_count{1000};
int count{0};
std::mutex count_mutex;
std::condition_variable count_threshold;


void inc_count()
{
	for (int i=0; i < t_count; ++i) {
		unique_lock<mutex> mlock(count_mutex);
		++count;

		// check the value of count and signal waiting thread
		//     when condition is reached.
		// note that this occur while mutex is locked: be careful!
		if (count == count_limit)
			count_threshold.notify_one();
		mlock.unlock();

		// sleep so that threads can alternate on mutex lock
		// but in the real world you should work now :)
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}

void watch_count()
{
	cout << "Starting watch_count thread\n";

	// Lock mutex and wait for signal. 
	// Be careful: the count limit could be reached before
	// this thread executes the wait.
	unique_lock<mutex> mlock(count_mutex);
	while (count < count_limit)
		count_threshold.wait(mlock);
	mlock.unlock();
	cout << count_limit << " limit reached\n";
}

int main()
{
	thread inc_thread1{inc_count};
	thread inc_thread2{inc_count};
	thread watch_thread{watch_count};

	cout << "Main thread: wait thread to end\n";
	inc_thread1.join();
	inc_thread2.join();
	watch_thread.join();

	cout << "Final value of count: " << count << endl;

	return 0;
}