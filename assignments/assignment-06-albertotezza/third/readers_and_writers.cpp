// readers_and_writers.cpp

#include "readers_and_writers.h"
#include <mutex>
using std::mutex;
using std::unique_lock;

RW::RW()
:readers_{0}, readersBlocked_{0}, writers_{0}, writersBlocked_{0}
{}

void RW::StartRead(){
	unique_lock<mutex> mlock(mutex_);
	if( (readers_!=0) || (writersBlocked_!=0) ) {
    OKToRead_.wait(mlock);
    ++readersBlocked_;
  }
	++readers_;
	OKToRead_.notify_one();
  --readersBlocked_;
}

void RW::EndRead(){
	unique_lock<mutex> mlock(mutex_);
  --readers_;
  if(readers_==0) {
    OKToWrite_.notify_one();
		if(writersBlocked_)
    	--writersBlocked_;
  }
}

void RW::StartWrite(){
	unique_lock<mutex> mlock(mutex_);
	if( (readers_!=0) || (writers_!=0) ) {
    OKToWrite_.wait(mlock);
    ++writersBlocked_;
  }
	++writers_;
}

void RW::EndWrite(){
	unique_lock<mutex> mlock(mutex_);
  --writers_;
  if( readersBlocked_ == 0 ) {
    OKToWrite_.notify_one();
		if(writersBlocked_)
    	--writersBlocked_;
  }
  else {
    OKToRead_.notify_one();
		if (readersBlocked_)
    	--readersBlocked_;
  }
}
