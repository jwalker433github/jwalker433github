#pragma once
// FactoryManager.hpp
#include <string>
#include "tinyxml2.h"
#include "IObject.hpp"
#include "ObjectFactory.hpp"
#include "ObjectDictionary.hpp"

class FactoryManager : public IObject {
public:
    FactoryManager(const std::string& objectId) : IObject(objectId) {}
    virtual ~FactoryManager() = default;

    // Start function
    void start(const std::string& xmlFileName);

    // ... other member functions, if any ...
};
