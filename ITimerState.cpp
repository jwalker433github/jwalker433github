
// ITimerState.cpp
#include "ITimerState.hpp"
#include <iostream>

ITimerState::ITimerState(const std::string& objectId, 
		         const std::string& timerManager)
    : IState(objectId),
      m_timerManagerId(timerManager)
{
}

bool ITimerState::init() {
    // Call the parent's init function
    if (!IState::init()) {
        return false;
    }
    return true;
}

void ITimerState::start() {
    // Call the parent's start function
    IState::start();
}

void ITimerState::run() {
    // Call the parent's run function
    IState::run();
}

void ITimerState::print() {
    // Call the parent's print function
    IState::print();
    // Perform the print specific to ITimerState
    std::cout << "Timer State ObjectId: " << getObjectId() << std::endl;
}

void ITimerState::enter(IFsm* ) {
    // Implementation for enter
}

void ITimerState::exit(IFsm* ) {
    // Implementation for exit
}

LogicalState ITimerState::processEvent(IFsm* , IEvent* ) 
{
    // Implementation for processEvent
    return LogicalState::NoStateChange;
}
