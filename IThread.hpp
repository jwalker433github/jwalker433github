#pragma once 
// IThread.h
#include <string>
#include <thread>
#include "IObject.hpp"
#include <memory>

class IThread : public IObject {
public:
    IThread(const std::string& objectId, const std::string& targetObjectId);
    virtual ~IThread();

    // Inherited member functions from IObject
    virtual bool init() override;
    virtual void start() override;
    virtual void run() override;
    virtual void print() override;

private:
    std::string m_targetObjectId;
    IObject*    m_target;
    std::thread m_thread;
};

