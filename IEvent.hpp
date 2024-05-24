#pragma once
// IEvent.hpp
#include <string>
#include "IObject.hpp"

class IEvent : public IObject {
public:
    IEvent(const std::string& objectId, const std::string& eventId);
    virtual ~IEvent() = default;

    // Getter for EventId
    const std::string& getEventId() const;

    // Inherited member functions from IObject
    virtual bool init() override;
    virtual void start() override;
    virtual void run() override;
    virtual void print() override;

private:
    std::string eventId;
};

