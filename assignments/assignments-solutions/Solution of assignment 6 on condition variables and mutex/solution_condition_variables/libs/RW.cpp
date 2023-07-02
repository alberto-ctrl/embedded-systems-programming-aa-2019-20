#include <iostream>
using std::cout;
using std::endl;
#include <thread>
#include <mutex>
using std::mutex;
using std::unique_lock;
#include "RW.h"

RW::RW()
:data_{0}, readers_{0}, writers_{0}
{}

// operation StartRead
//	if writers != 0 or not empty (OKtoWrite)
//		waitC(OKtoRead)
//	readers = readers + 1
//	signalC(OKtoRead)
void RW::start_read()
{
	unique_lock<mutex> mlock(mutex_);
	// must use while for spourious wake ups
	while ((writers_ != 0) || (waiting_writers_ > 0)) {
		waiting_readers_++;
		OK_to_read_.wait(mlock);
		/*if (writers_ == 0)
			break;*/
		waiting_readers_--;
	}
	readers_++;
}


//operation EndRead
//	readers = readers - 1
//	if readers = 0
//		signalC(OKtoWrite)
void RW::end_read()
{
	unique_lock<mutex> mlock(mutex_);
	readers_--;
	if (readers_ = 0)
		OK_to_write_.notify_one();

}


//operation StartWrite
//	if writers != 0 or readers != 0
//		waitC(OKtoWrite)
//	writers = writers - 1
void RW::start_write()
{
	unique_lock<mutex> mlock(mutex_);
	while ( (writers_ != 0) || (readers_ != 0) ) {
		waiting_writers_++;
		OK_to_write_.wait(mlock);
		waiting_writers_--;
	}
	writers_++;
}


//operation EndWrite
//	writers = writers - 1
//	if (empty(OKtoRead))
//	then signalC(OKtoWrite)
//	else signalC(OKtoRead)
void RW::end_write()
{
	cout << "Done with write" << writers_ << "\n";
	unique_lock<mutex> mlock(mutex_);
	writers_--;

	if (waiting_readers_ > 0)
		OK_to_read_.notify_all();
	else
		OK_to_write_.notify_one();
}
