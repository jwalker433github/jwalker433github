
// IFsm.cpp
#include "IFsm.hpp"

IFsm::IFsm(const std::string& objectId) : IEventProcessor(objectId), currentState(nullptr) {}

void IFsm::processEvent(IEvent* event) {
    if (currentState == nullptr) {
        return;
    }

    LogicalState stateChange = currentState->processEvent(this, event);

    if (stateChange != LogicalState::NoStateChange) {
        currentState->exit(this);
        IState* newState = currentState->getState(stateChange);
        newState->enter(this);
        currentState = newState;
    }
}

bool IFsm::init() {
    // Call the parent's init function
    if (!IEventProcessor::init()) {
        return false;
    }
    // Perform initialization specific to IFsm
    // ...
    return true;
}

void IFsm::start() {
    // Call the parent's start function
    IEventProcessor::start();
    // Perform the start specific to IFsm
    // ...
}

void IFsm::run() {
    // Call the parent's run function
    IEventProcessor::run();
    // Perform the run specific to IFsm
    // ...
}

void IFsm::print() {
    // Call the parent's print function
    IEventProcessor::print();
    // Perform the print specific to IFsm
    // ...
}
