// IEventProcessor.cpp
#include "IEventProcessor.hpp"
#include <iostream>

IEventProcessor::IEventProcessor(const std::string& objectId)
    : IObject(objectId) {}

bool IEventProcessor::init() {
    // Call the parent's init function
    if (!IObject::init()) {
        return false;
    }
    // Perform initialization specific to IEventProcessor
    // ...
    return true;
}

void IEventProcessor::start() {
    // Call the parent's start function
    IObject::start();
    // Perform the start specific to IEventProcessor
    // ...
}

void IEventProcessor::run() {
    // Call the parent's run function
    IObject::run();
    // Perform the run specific to IEventProcessor
    // ...
}

void IEventProcessor::print() {
    // Call the parent's print function
    IObject::print();
    // Perform the print specific to IEventProcessor
    // ...
}
