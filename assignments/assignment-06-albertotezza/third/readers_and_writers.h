// PC.h

#ifndef readers_and_writers_H
#define readers_and_writers_H

#include <vector>
#include <mutex>
#include <condition_variable>

class RW {
public:
    RW(); // uso queue non mi serve un costruttore per definire il container
    void StartRead();
    void EndRead();
    void StartWrite();
    void EndWrite();

private:
    int readers_;
    int readersBlocked_;
    int writers_;
    int writersBlocked_;

    std::mutex mutex_;
    std::condition_variable OKToRead_;
    std::condition_variable OKToWrite_;

};

#endif
