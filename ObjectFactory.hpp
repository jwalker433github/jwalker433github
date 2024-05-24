#pragma once
// ObjectFactory.h
#include <unordered_map>
#include <string>
#include <functional>
#include <memory>
#include "IObject.hpp"

class ObjectFactory {
public:
    template <typename T>
    void registerObject(const std::string& objectId) {
        m_factoryMap[objectId] = [](const std::string& objectId) -> std::shared_ptr<IObject> {
            return std::make_shared<T>(objectId);
        };
    }

    std::shared_ptr<IObject> createObject(const std::string& objectId) {
        auto it = m_factoryMap.find(objectId);
        if (it != m_factoryMap.end()) {
            return it->second(objectId);
        }
        return nullptr;
    }

private:
    std::unordered_map<std::string, std::function<std::shared_ptr<IObject>(const std::string&)>> m_factoryMap;
};
