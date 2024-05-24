
// ITimedEventState.cpp
#include "ITimedEventState.hpp"
#include "ObjectDictionary.hpp"
#include <iostream>

ITimedEventState::ITimedEventState(const std::string& objectId,
	                           const std::string& timerId,	
		                   const std::string& eventSenderId)
    : ITimerState(objectId,
		  timerId), 
      m_eventSenderId(eventSenderId) {}

ITimedEventState::~ITimedEventState() {}

bool ITimedEventState::init() {
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

void ITimedEventState::start() {
    // Call the parent's start function
    ITimerState::start();
}

void ITimedEventState::run() {
    // Call the parent's run function
    ITimerState::run();
}

void ITimedEventState::print() {
    // Call the parent's print function
    ITimerState::print();
    // Perform the print specific to ITimedEventState
    std::cout << "Event Sender Object ID: " << m_eventSenderId << std::endl;
}

void ITimedEventState::enter(IFsm* fsm) {
    // Call ITimerState enter function
    ITimerState::enter(fsm);

    // Call eventSender sendEvent function
    m_eventSender->sendEvent();
}
