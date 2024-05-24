
// IEvent.cpp
#include "IEvent.hpp"
#include <iostream>

IEvent::IEvent(const std::string& objectId, const std::string& eventId)
    : IObject(objectId), eventId(eventId) {}

const std::string& IEvent::getEventId() const {
    return eventId;
}

bool IEvent::init() {
    // Call the parent's init function
    if (!IObject::init()) {
        return false;
    }
    // Perform initialization specific to IEvent
    // ...
    return true;
}

void IEvent::start() {
    // Call the parent's start function
    IObject::start();
    // Perform the start specific to IEvent
    // ...
}

void IEvent::run() {
    // Call the parent's run function
    IObject::run();
    // Perform the run specific to IEvent
    // ...
}

void IEvent::print() {
    // Call the parent's print function
    IObject::print();
    // Perform the print specific to IEvent
    std::cout << "EventId: " << eventId << std::endl;
}
