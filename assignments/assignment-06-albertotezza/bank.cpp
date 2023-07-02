#include <iostream>
using std::cout;
using std::endl;
#include <thread>
using std::thread;
	#include <mutex>
	using std::mutex;

const int limit{50}; // low balance limit
const int withdraw_num{20};

double balance{0};
int i{0}; // num of withdraw so far

 mutex my_mutex;

void depositor(int dep_num)
{
	for (int j=0; j<dep_num; ++j) {

		double deposit = 100; // generate a random amount of deposit

		my_mutex.lock();
		balance += deposit;

		cout << j << "-th deposit of: " << deposit << " - balance is " << balance << endl;
		my_mutex.unlock();

		std::this_thread::sleep_for(std::chrono::milliseconds(250));
	}

}

void withdrawer(int myID)
{
	while (i < withdraw_num) {
		double debt = 50;

		if ( (balance - debt) < limit )

			cout << "sorry you cannot withdraw\n";
		else {
			my_mutex.lock();
			balance -= debt;
			cout << i << "-th withdraw by " << myID << " of " << debt << " balance: " << balance << endl;
			my_mutex.unlock();
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(250));
		++i;
	}


}

int main()
{
	thread depositor_thread{depositor, 10};
	thread withdrawer_thread1{withdrawer, 0};
	thread withdrawer_thread2{withdrawer, 1};

	depositor_thread.join();
	withdrawer_thread1.join();
	withdrawer_thread2.join();

	return 0;
}
