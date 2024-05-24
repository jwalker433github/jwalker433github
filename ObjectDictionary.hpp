#pragma once
// ObjectDictionary.hpp
#include <string>
#include <unordered_map>
#include <memory>
#include "IObject.hpp"

class ObjectDictionary {
public:
    static ObjectDictionary* getInstance();
    static ObjectDictionary*  instance;
    void addObject(const std::string& objectId, IObject* object);
    IObject* getObject(const std::string& objectId);
    bool removeObject(const std::string& objectId);

private:
    ObjectDictionary() = default;
    ~ObjectDictionary() = default;
    ObjectDictionary(const ObjectDictionary&) = delete;
    ObjectDictionary& operator=(const ObjectDictionary&) = delete;

    std::unordered_map<std::string, IObject*> m_objects;
};

