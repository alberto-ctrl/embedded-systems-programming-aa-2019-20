#include <iostream>
using std::cout;
using std::endl;
#include <thread>
#include "readers_and_writers.h"

RW q;

void reader(int id){
        q.StartRead();
        cout << "reader: " << id << ", is reading . . ." << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        q.EndRead();
        cout << "reader: " << id << ", have READ." << endl;
}

void writer(int id){
        q.StartWrite();
        cout << "writer: " << id << ", is writing . . ." << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(3500));
        q.EndWrite();
        cout << "writer: " << id << ", have WRITE." << endl;
}

int main(){

  std::thread w1(writer, 0);
  std::thread w2(writer, 1);

    std::thread r1(reader, 1);
    std::thread r2(reader, 2);
    std::thread r3(reader, 3);
    std::thread r4(reader, 4);



    r1.join();
    r2.join();
    r3.join();
    r4.join();
    w1.join();
    w2.join();

    return 0;
}
