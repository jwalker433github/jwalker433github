#pragma once
// ITimedEventState.hpp
#include <string>
#include "ITimerState.hpp"
#include "ISendEvent.hpp"
#include <memory>

class ITimedEventState : public ITimerState {
public:
    ITimedEventState(const std::string& objectId, 
		     const std::string& timerId,
		     const std::string& eventSenderId);
    virtual ~ITimedEventState();

    // Inherited member functions from IObject
    virtual bool init() override;
    virtual void start() override;
    virtual void run() override;
    virtual void print() override;

    // Overridden member functions from ITimerState
    virtual void enter(IFsm* fsm) override;

private:
    const std::string&          m_eventSenderId;
    ISendEvent*                 m_eventSender;
};

