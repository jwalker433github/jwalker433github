#pragma once
#include <string>
/**
This class has a constructor that takes a std::string argument to initialize ObjectId. It also includes getter and setter methods for the ObjectId attribute. The main function demonstrates how to create an instance of the IObject class, set its ObjectId, and retrieve its value.
*/
class IObject {
public:
    const std::string& m_objectId;
    IObject(const std::string& objectId) : m_objectId(objectId) {}
    virtual ~IObject() = default;

    // Init function
    virtual bool init() {return true;}

    // Start function
    virtual void start() {}

    // Run function
    virtual void run() {}

    virtual void reset() {}

    virtual bool lock() {return true;}

    // Getter for ObjectId
    const std::string& getObjectId() const {
        return m_objectId;
    }

    virtual void print() {}
private:

};
