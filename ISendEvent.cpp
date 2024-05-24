
// ISendEvent.cpp
#include "ISendEvent.hpp"
#include "ObjectDictionary.hpp"
#include <iostream>

ISendEvent::ISendEvent(const std::string& objectId, const std::string& eventId, const std::string& destinationId)
    : IObject(objectId), eventId(eventId), destinationId(destinationId) {}

void ISendEvent::sendEvent() {
    if (destination) {
        destination->processEvent(txEvent);
    }
}

bool ISendEvent::init() {
    // Call the parent's init function
    if (!IObject::init()) {
        return false;
    }

    // Get the txEvent and destination from the ObjectDictionary
    txEvent     = dynamic_cast<IEvent*>(ObjectDictionary::instance->getObject(eventId));
    destination = dynamic_cast<IEventProcessor*>(ObjectDictionary::getInstance()->getObject(destinationId));

    return true;
}

void ISendEvent::start() {
    // Call the parent's start function
    IObject::start();
    // Perform the start specific to ISendEvent
    // ...
}

void ISendEvent::run() {
    // Call the parent's run function
    IObject::run();
    // Perform the run specific to ISendEvent
    // ...
}

void ISendEvent::print() {
    // Call the parent's print function
    IObject::print();
    // Perform the print specific to ISendEvent
    std::cout << "Event ID: " << eventId << std::endl;
    std::cout << "Destination ID: " << destinationId << std::endl;
}
