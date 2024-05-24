#pragma once
// ITimerState.hpp
#include <string>
#include "IState.hpp"
#include "ITimerManager.hpp"
#include "MyTimer.hpp"
#include "IFsm.hpp"
#include <memory>
class ITimerState : public IState {
public:
    ITimerState(const std::string& objectId, const std::string& timerManager);

    // Inherited member functions from IObject
    virtual bool init() override;
    virtual void start() override;
    virtual void run() override;
    virtual void print() override;

    // Inherited member functions from IState
    virtual void enter(IFsm* fsm) override;
    virtual void exit(IFsm* fsm) override;
    virtual LogicalState processEvent(IFsm* fsm, IEvent* event) override;

private:
    std::shared_ptr<ITimerManager> m_timerManager;
    std::string                    m_timerManagerId;
    std::shared_ptr<MyTimer> m_timer;
};

