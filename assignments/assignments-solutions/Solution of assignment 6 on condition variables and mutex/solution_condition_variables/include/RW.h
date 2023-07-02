// RW.h

#ifndef RW_H
#define RW_h

#include <mutex>
#include <condition_variable>

class RW {
public:
	RW();
	void start_read();
	void end_read();
	void start_write();
	void end_write();
	void incr_data() { data_++; }
	int get_data() { return data_;}

private:
	int data_;
	int readers_;
	int writers_;
	int waiting_writers_;
	int waiting_readers_;
	std::mutex mutex_;   // RW monitor lock
	std::condition_variable OK_to_read_;
	std::condition_variable OK_to_write_;
};

#endif