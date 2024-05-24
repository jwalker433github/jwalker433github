#pragma once
#include <memory>
#include "IEventProcessor.hpp"
#include "IEvent.hpp"
#include "LogicalState.hpp"

class EventHandler 
{
  public:
    virtual ~EventHandler() = default;

    virtual LogicalState processEvent(IEventProcessor* fsm, IEvent* event) = 0;


};

