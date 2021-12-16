#include <iostream>
#include <thread>
#include <semaphore>
#include <mutex>
#include <string>

class Fork {
public:
    std::binary_semaphore semaphore = std::binary_semaphore(1);

    void take() {
        semaphore.acquire();
    }

    void put() {
        semaphore.release();
    }
};

std::mutex mutex;
void print(const std::string& str) {
    mutex.lock();
    std::cout << str << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    mutex.unlock();
}

void philosopherBehavior(Fork* forks, int num) {
    int leftForkNum = num;
    int rightForkNum = (num + 1) % 5;
    if (leftForkNum > rightForkNum)
        std::swap(leftForkNum, rightForkNum);
    Fork& leftFork = forks[leftForkNum];
    Fork& rightFork = forks[rightForkNum];

    for (int i = 0; i < 3; i++) {
        print(std::string("Philosopher#") + std::to_string(num + 1) + " is thinking");
        std::this_thread::sleep_for(std::chrono::seconds(1));
        leftFork.take();
        print(std::string("Philosopher#") + std::to_string(num + 1) + " takes his left fork (fork #" + std::to_string(num + 1) + ")");
        rightFork.take();
        print(std::string("Philosopher#") + std::to_string(num + 1) + " takes his right fork (fork #" + std::to_string(((num + 1) % 5 ) + 1) + ")");
        std::this_thread::sleep_for(std::chrono::seconds(1));
        print(std::string("Philosopher#") + std::to_string(num + 1) + " has eaten");
        rightFork.put();
        leftFork.put();
    }
}

int main() {
    std::cout << "==> Start" << "\n";

    Fork* forks = new Fork[5];
    std::thread* philosophers = new std::thread[5];
    for (int i = 0; i < 5; i++) {
        philosophers[i] = std::thread(philosopherBehavior, forks, i);

    }
    for (int i = 0; i < 5; i++) {
        philosophers[i].join();
    }

    delete[] forks;
    delete[] philosophers;

    std::cout << "==> Finish";
    return 0;
}
