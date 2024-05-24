
// IState.cpp
#include "IState.hpp"
#include <iostream>

IState::IState(const std::string& objectId) : IObject(objectId) {}

bool IState::init() {
    // Call the parent's init function
    if (!IObject::init()) {
        return false;
    }

    // Perform the init specific to IState
    // ...

    return true;
}

void IState::start() {
    // Call the parent's start function
    IObject::start();
    // Perform the start specific to IState
    // ...
}

void IState::run() {
    // Call the parent's run function
    IObject::run();
    // Perform the run specific to IState
    // ...
}

void IState::print() {
    // Call the parent's print function
    IObject::print();
    // Perform the print specific to IState
    // ...
}
