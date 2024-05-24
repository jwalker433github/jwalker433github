#pragma once
#include <unordered_map>
#include <memory>
#include "IState.hpp"
#include "EventHandler.hpp"

class LogicalStateTranslator : public IState {
public:
    LogicalStateTranslator(const std::string &objectId);

    void addEventHandler(const std::string &eventId, EventHandler* handler);
    void addState(LogicalState logicalState, IState* state);

    LogicalState processEvent(IFsm* fsm, IEvent* event) override;
    bool init() override;
    void start() override;
    void print() override;

private:
    std::unordered_map<std::string,  EventHandler*> eventHandlers;
    std::unordered_map<LogicalState, IState*>       stateDictionary;
};
