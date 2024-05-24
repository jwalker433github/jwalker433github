#pragma once
// IEventProcessor.hpp
#include <string>
#include "IObject.hpp"
#include "IEvent.hpp"
#include <memory>

class IEventProcessor : public IObject {
public:
    IEventProcessor(const std::string& objectId);
    virtual ~IEventProcessor() = default;

    virtual void processEvent(IEvent* event) = 0;

    // Inherited member functions from IObject
    virtual bool init() override;
    virtual void start() override;
    virtual void run() override;
    virtual void print() override;
};

