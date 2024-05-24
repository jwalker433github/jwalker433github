
// ObjectDictionary.cpp
#include "ObjectDictionary.hpp"

ObjectDictionary* ObjectDictionary::instance = 0;

ObjectDictionary* ObjectDictionary::getInstance() {
    static ObjectDictionary instance;
    return &instance;
}

void ObjectDictionary::addObject(const std::string& objectId, IObject* object) {
    m_objects[objectId] = object;
}

IObject* ObjectDictionary::getObject(const std::string& objectId) {
    auto it = m_objects.find(objectId);
    if (it != m_objects.end()) {
        return it->second;
    }
    return nullptr;
}

bool ObjectDictionary::removeObject(const std::string& objectId) {
    auto it = m_objects.find(objectId);
    if (it != m_objects.end()) {
        m_objects.erase(it);
        return true;
    }
    return false;
}
