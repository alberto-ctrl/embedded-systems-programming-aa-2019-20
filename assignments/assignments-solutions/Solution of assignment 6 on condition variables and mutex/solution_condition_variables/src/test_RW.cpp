// test_RW.cpp 
// This solution works in a scenario where writers
// are not continously asking to write, otherwise we
// would get readers starvation 
//
// This is a reasonable hypothesis as usually writing action
// is more important than the reading action but 
// happens less frequently

#include <iostream>
using std::cout;
using std::endl;
#include <thread>
#include "RW.h"

RW rw;

void writer( int myID, int write_loop ){
	for (int i = 0; i < write_loop; ++i) {
		rw.start_write();
		cout << myID << "-writer [" << i << "-th loop]\n";
		rw.incr_data();
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		rw.end_write();
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
	}
}

void reader(int myID, int read_loop) {
	for (int i = 0; i < read_loop; ++i) {
		rw.start_read();
		int data = rw.get_data();
		cout << myID << "-reader [" << i << "-th loop ]:" << data << endl;
		rw.end_read();
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
}

int main() {
	
	std::thread r1{reader, 0, 60};
	std::thread r2{reader, 1, 60};
	std::thread r3{reader, 1, 60};
	std::thread r4{reader, 1, 60};
	std::thread r5{reader, 1, 60}; 
	
	std::thread w1{writer, 0, 5};
	


	w1.join();
	r1.join();
	r2.join();
	r3.join();
	r4.join();
	r5.join();

	cout << "End of main thread, current value of data_ " << rw.get_data() << endl;

	return 0;
}

