#include <iostream>
#include <thread>
#include <unistd.h>

void callNewThread(int n) {
    std::cout << "Thread number: " << n << std::endl;
}

int main() {
    std::thread t1(callNewThread, 1);
    sleep(1);
    std::thread t2(callNewThread, 2);

    std::cout << "Main thread" << std::endl;

    t1.join();
    t2.join();

    return 0;
}
