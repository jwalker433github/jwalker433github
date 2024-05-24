
// ITimedSendEventState.cpp
#include "ITimedSendEventState.hpp"
#include "ObjectDictionary.hpp"
#include <iostream>

ITimedSendEventState::
ITimedSendEventState(const std::string& objectId,
	             const std::string& timerManager,	
                     const std::string& eventSenderId)
    : ITimerState(objectId, timerManager), 
      m_eventSenderId(eventSenderId) 
{
}

ITimedSendEventState::~ITimedSendEventState() {}

bool ITimedSendEventState::init() {
    // Call the parent's init function
    if (!ITimerState::init()) {
        return false;
    }

    // Get the eventSender object from the ObjectDictionary
    m_eventSender = dynamic_cast<ISendEvent*>(ObjectDictionary::getInstance()->getObject(m_eventSenderId));
    if (!m_eventSender) {
        return false;
    }

    return true;
}

void ITimedSendEventState::start() {
    // Call the parent's start function
    ITimerState::start();
}

void ITimedSendEventState::run() {
    // Call the parent's run function
    ITimerState::run();
}

void ITimedSendEventState::print() {
    // Call the parent's print function
    ITimerState::print();
    // Perform the print specific to ITimedSendEventState
    std::cout << "Event Sender Object ID: " << m_eventSenderId << std::endl;
}

void ITimedSendEventState::enter(IFsm* fsm) {
    // Call ITimerState enter function
    ITimerState::enter(fsm);

    // Call eventSender sendEvent function
    m_eventSender->sendEvent();
}
