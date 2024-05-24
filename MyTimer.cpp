#include <iostream>
#include <functional>
#include "MyTimer.hpp"

MyTimer::MyTimer(const std::string &objectId)
	    : IObject(objectId), 
	      callback(nullptr), 
	      currentTime(0),
	      m_next(nullptr), 
	      m_prev(nullptr)
{
}

void MyTimer::setCallback(std::function<void()> cb) {
            callback = cb;
}

void MyTimer::setTime(int time) {
	    m_remainingTime = time;
}

int MyTimer::getTime() const {
	    return m_remainingTime;
}

void MyTimer::callCallback() {
	    if (callback) 
	    {
	      callback();
	    }
}

MyTimer* MyTimer::getNext() const {
	    return m_next;
}

void MyTimer::setNext(MyTimer* nextTimer) {
	   m_next = nextTimer;
}

MyTimer* MyTimer::getPrev() const {
	    return m_prev;
}

void MyTimer::setPrev(MyTimer* prevTimer) {
	    m_prev = prevTimer;
}

bool MyTimer::init() {
	   return  IObject::init();
	    //	Any additional initialization logic for MyTimer
}
		
 void MyTimer::start() {
    	IObject::start();
         // Any additional start logic for MyTimer
}
//
void MyTimer::stop() {
	
	// Any additional stop logic for stop
}
//
void MyTimer::print() {
	IObject::print();
//	std::cout << "MyTimer objectId: " << objectId << std::endl;
}
                        
