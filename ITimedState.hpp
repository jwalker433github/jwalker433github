#include "ITimerState.h"
#include "ISendEvent.h"

class ITimedSendEventState : public ITimerState {
public:
    ITimedSendEventState(const std::string& objectId, std::shared_ptr<ISendEvent> eventSender)
        : ITimerState(objectId), eventSender(eventSender) {}

    void enter(std::shared_ptr<IEventProcessor> fsm) override {
        ITimerState::enter(fsm);
        if (eventSender) {
            eventSender->sendEvent();
        }
    }

private:
    std::shared_ptr<ISendEvent> eventSender;
};
