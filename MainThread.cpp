// main.cpp
#include "factorymanager.h"
#include <iostream>
#include <string>
#include <thread>
#include <condition_variable>
#include <mutex>

std::condition_variable cv;
std::mutex mtx;

void mainThread(const std::string& xmlFilename) {
    FactoryManager factoryManager;
    factoryManager.start(xmlFilename);

    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <XML file>" << std::endl;
        return 1;
    }

    std::string xmlFilename = argv[1];

    std::thread t(mainThread, xmlFilename);
    t.join();

    return 0;
}
