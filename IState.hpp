#pragma once
// IState.h
#include <string>
#include "IObject.hpp"
//#include "IFsm.hpp"
#include "IEvent.hpp"
#include "LogicalState.hpp"
#include <memory>

class IFsm;

class IState : public IObject {
public:
    IState(const std::string& objectId);
    virtual ~IState() = default;

    // State-specific member functions
    virtual void enter(IFsm* ) {}
    virtual void exit(IFsm* ) {};
    virtual LogicalState processEvent(IFsm* , IEvent* ){return LogicalState::NoStateChange;}
    virtual IState* getState(LogicalState) {return this;}
    // Inherited member functions from IObject
    virtual bool init() override;
    virtual void start() override;
    virtual void run() override;
    virtual void print() override;
};

