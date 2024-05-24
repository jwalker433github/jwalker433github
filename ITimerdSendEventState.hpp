#pragma once
// ITimedSendEventState.hpp
#include <string>
#include "ITimerState.hpp"
#include "ISendEvent.hpp"

class ITimedSendEventState : public ITimerState {
public:
    ITimedSendEventState(const std::string& objectId, const std::string& eventSenderId);
    virtual ~ITimedSendEventState();

    // Inherited member functions from IObject
    virtual bool init() override;
    virtual void start() override;
    virtual void run() override;
    virtual void print() override;

    // Overridden member functions from ITimerState
    virtual void enter(std::shared_ptr<IEventProcessor> fsm) override;

private:
    std::string m_eventSenderId;
    std::shared_ptr<ISendEvent> m_eventSender;
};

