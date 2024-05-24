#pragma once
#include <functional>
#include "IObject.hpp"

class MyTimer : public IObject 
{
  public:
     MyTimer(const std::string &objectId);

     void setCallback(std::function<void()> cb);
     void setTime(int time);
     int getTime() const;
     void callCallback();

     MyTimer* getNext() const;
     void setNext(MyTimer* nextTimer);
     MyTimer* getPrev() const;
     void setPrev(MyTimer* prevTimer);

     bool init() override;
     void start() override;
     void stop();
     void print() override;
     int  m_remainingTime;

  //private:
     std::function<void()> callback;
     int currentTime;
     MyTimer* m_next;
     MyTimer* m_prev;
};
