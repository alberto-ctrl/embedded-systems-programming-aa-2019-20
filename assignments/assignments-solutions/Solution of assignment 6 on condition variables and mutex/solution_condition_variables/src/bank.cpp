// bank.cpp - solution
//
// There are still two problems on these solutions. 
// I wrote them at the end of the file but, first, 
// can you find them looking at the code?

#include <iostream>
using std::cout;
using std::endl;
#include <thread>
using std::thread;
#include <mutex>
using std::mutex;
using std::unique_lock;
#include <condition_variable>
using std::condition_variable;

const int limit{50}; // low balance limit
const int withdraw_num{20};

double balance{0};
int i{0}; // num of withdraw so far
condition_variable above_limit;
mutex balance_mutex;


void depositor(int dep_num) 
{
	for (int j=0; j<dep_num; ++j) {
		double deposit = 100; 
		unique_lock<mutex> mlock(balance_mutex);
		balance += deposit;
		double balance_copy{balance};
		if (balance >= limit)
			above_limit.notify_one();
		mlock.unlock();
		// Don't put the output inside CS, and make a copy of balance before
		// so you are not reading a shared variable outside CS
		cout << j << "-th deposit of: " << deposit << " - balance is " << balance_copy << endl;

		std::this_thread::sleep_for(std::chrono::milliseconds(250));
	}

}

void withdrawer(int myID)
{
	while (i < withdraw_num) {
		double debt = 50;
		unique_lock<mutex> mlock(balance_mutex);
		while ((balance-debt) < limit) 
			above_limit.wait(mlock);
		
		balance -= debt;
		++i;
		double balance_copy{balance};
		int i_copy{i};
		mlock.unlock();

		cout << i_copy << "-th withdraw by " << myID << " of " << debt << " balance: " << balance_copy << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
	}
}

int main()
{
	thread depositor_thread{depositor, 20};
	thread withdrawer_thread1{withdrawer, 0};
	thread withdrawer_thread2{withdrawer, 1};

	depositor_thread.join();
	withdrawer_thread1.join();
	withdrawer_thread2.join();

	return 0;
}

// Problem 1. it may happen that two withdrawers are waiting on above_limit. 
//      The first one unblock, withdraw debt and increment i reaching the withdraw_num value
//      When the second one unblock, it will withdraw another time so we will go over the withdraw_num limit
// Solution: You should add additional check of i < withdraw_num
// 
// Problem 2. if the depositor reaches its limit before the withdrawers the latest could block foverer waiting 
//      a notification that will never arrive
// Solution: You should add an additional global boolean variable to set when it is time to exit and
//           the main thread should notify_all the withdrawers if required.