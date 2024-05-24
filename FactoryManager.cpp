
// FactoryManager.cpp
#include "FactoryManager.hpp"

void FactoryManager::start(const std::string& xmlFileName) {
    // Open the XML file
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLError result = doc.LoadFile(xmlFileName.c_str());

    if (result != tinyxml2::XML_SUCCESS) {
        // Handle error
        return;
    }

    // Iterate through the XML file and create IObject instances
    tinyxml2::XMLElement* rootElement = doc.RootElement();
    for (tinyxml2::XMLElement* elem = rootElement->FirstChildElement(); elem != nullptr; elem = elem->NextSiblingElement()) {
        // Get the object class and object ID from the XML attributes
        std::string objectClass = elem->Attribute("class");
        std::string objectId = elem->Attribute("id");

        // Call ObjectFactory's Create function to create the IObject instance
        IObject* object = ObjectFactory::Create(objectClass, objectId);

        // Add the created object to the ObjectDictionary
        ObjectDictionary::getInstance().addObject(objectId, object);
    }

    // Iterate through all objects in the ObjectDictionary and call their init function
    for (auto& objectPair : ObjectDictionary::getInstance().getObjects()) {
        objectPair.second->init();
    }

    // Iterate through all objects in the ObjectDictionary and call their start function
    for (auto& objectPair : ObjectDictionary::getInstance().getObjects()) {
        if (auto startable = dynamic_cast<IStartable*>(objectPair.second)) {
            startable->start();
        }
    }
}
