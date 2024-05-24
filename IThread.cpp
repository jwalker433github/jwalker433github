// IThread.cpp
#include "IThread.hpp"
#include "ObjectDictionary.hpp"
#include <iostream>

IThread::IThread(const std::string& objectId, const std::string& targetObjectId)
    : IObject(objectId), m_targetObjectId(targetObjectId) {}

IThread::~IThread() {
    if (m_thread.joinable()) {
        m_thread.join();
    }
}

bool IThread::init() {
    // Call the parent's init function
    if (!IObject::init()) {
        return false;
    }

    // Get the target object from the ObjectDictionary
    m_target = ObjectDictionary::getInstance()->getObject(m_targetObjectId);
    if (!m_target) {
        return false;
    }

    return true;
}
/*
The start member function of the IThread class is responsible for creating a new thread that executes the run method of the target object (ITarget).

Here's a step-by-step explanation of the start function:

    It checks whether the ITarget pointer is not nullptr. If ITarget is nullptr, it means the target object has not been initialized, so the function does not proceed further.

    If ITarget is not nullptr, it creates a new std::thread object and assigns it to the Thread member variable. The std::thread constructor takes two arguments: the first is a pointer to the member function to execute in the new thread, in this case, &IThread::runWrapper. The second argument is the object on which to call the member function, which is this. This means that the runWrapper member function of the current IThread object will be executed in the new thread.

    After creating the new thread, the start function returns immediately. The new thread starts executing the runWrapper function concurrently with the original thread.

Note that the Thread member variable is an instance of std::thread, which represents the new thread created by the start function. This thread runs independently from the thread that called the start function, allowing for concurrent execution of the target object's run method.

Keep in mind that this implementation assumes the target object's run function is thread-safe. If it is not, you may need to implement synchronization mechanisms to ensure correct behavior.
*/
void IThread::start() {
    // Call the parent's start function
    IObject::start();

    // Launch the thread to call the target object's run function
    m_thread = std::thread(&IObject::run, m_target);
}

void IThread::run() {
    // Call the parent's run function
    IObject::run();
    // The run function for IThread is intentionally left empty
    // as the functionality is provided by the start function
}

void IThread::print() {
    // Call the parent's print function
    IObject::print();
    // Perform the print specific to IThread
    std::cout << "Target Object ID: " << m_targetObjectId << std::endl;
}
