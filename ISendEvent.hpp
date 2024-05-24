#pragma once
// ISendEvent.hpp
#include <string>
#include "IObject.hpp"
#include "IEventProcessor.hpp"
#include "IEvent.hpp"

class ISendEvent : public IObject {
public:
    ISendEvent(const std::string& objectId, const std::string& eventId, const std::string& destinationId);
    virtual ~ISendEvent() = default;

    void sendEvent();

    // Inherited member functions from IObject
    virtual bool init() override;
    virtual void start() override;
    virtual void run() override;
    virtual void print() override;

private:
    std::string eventId;
    std::string destinationId;
    IEvent*     txEvent;
    IEventProcessor* destination;
};

