
#pragma once
// ITimerManager.hpp
#include <array>
#include <memory>
#include <deque>
#include "IObject.hpp"
#include "MyTimer.hpp"

class ITimerManager : public IObject {
public:
    static constexpr size_t QueueSize = 256;

    ITimerManager(const std::string& objectId)
        : IObject(objectId), m_currentQueue(0) {}

    void addTimer(unsigned int interval, std::shared_ptr<MyTimer> timer) {
        size_t queueIndex = (m_currentQueue + interval) % QueueSize;
        timer->m_remainingTime = interval / QueueSize;
        m_queues[queueIndex].push_back(std::move(timer));
    }

    void tick() {
        m_currentQueue = (m_currentQueue + 1) % QueueSize;
        auto& queue = m_queues[m_currentQueue];
        while (!queue.empty()) {
            auto& timer = queue.front();
            if (timer->m_remainingTime > 0) {
                --timer->m_remainingTime;
                break;
            }
            timer->callback();
            queue.pop_front();
        }
    }

    bool stopTimer(const std::shared_ptr<MyTimer>& timer) {
        if (!timer || !timer->m_prev || !timer->m_next) {
            return false;
        }

        if (timer->m_prev->lock()) {
            timer->m_prev->m_next = timer->m_next;
        }
        timer->m_next->m_prev = timer->m_prev;

        timer->m_prev->reset();
        timer->m_next->reset();

        return true;
    }

private:
    size_t m_currentQueue;
    std::array<std::deque<std::shared_ptr<MyTimer>>, QueueSize> m_queues;
};
