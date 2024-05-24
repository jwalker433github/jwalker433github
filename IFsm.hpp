#pragma once
// IFsm.h
#include <string>
#include "IEventProcessor.hpp"
#include "IState.hpp"
#include "IEvent.hpp"
#include "LogicalState.hpp"
#include <memory>

class IFsm : public IEventProcessor {
public:
    IFsm(const std::string& objectId);
    virtual ~IFsm() = default;

    // Override processEvent from IEventProcessor
    void processEvent(IEvent* event) override;

    // Inherited member functions from IObject
    virtual bool init() override;
    virtual void start() override;
    virtual void run() override;
    virtual void print() override;

    // ... other member functions, if any ...

private:
    IState* currentState;
};
