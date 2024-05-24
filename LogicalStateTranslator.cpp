#include "LogicalStateTranslator.hpp"
#include "IFsm.hpp"
LogicalStateTranslator::LogicalStateTranslator(const std::string &objectId)
    : IState(objectId) {
}

void LogicalStateTranslator::addEventHandler(const std::string &eventId, EventHandler* handler) {
    eventHandlers[eventId] = handler;
}

void LogicalStateTranslator::addState(LogicalState logicalState, IState* state) {
    stateDictionary[logicalState] = state;
}

LogicalState LogicalStateTranslator::processEvent(IFsm* fsm, IEvent* event) {
    auto it = eventHandlers.find(event->getEventId());
    if (it != eventHandlers.end())
    {
//	IEventProcessor& eventProcessor = static_cast<IEventProcessor&> (fsm);
        return it->second->processEvent(fsm, event);
    } else {
        return LogicalState::NoStateChange;
    }
}

bool LogicalStateTranslator::init() {
    return IState::init();
    // Additional initialization if needed
}

void LogicalStateTranslator::start() {
    IState::start();
    // Additional start logic if needed
}

void LogicalStateTranslator::print() {
    IState::print();
    // Print other relevant information
    // ...
}
