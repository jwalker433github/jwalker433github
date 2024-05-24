
#include <iostream>
#include <memory>
#include "FactoryManager.hpp"
#include "IObject.hpp"
#include "IFsm.hpp"
#include "IEvent.hpp"
#include "IState.hpp"
#include "IThread.hpp"
#include "ITimerManager.hpp"
#include "ObjectDictionary.hpp"
#include "IFsm.hpp"
#include "IEvent.hpp"
#include "IState.hpp"
#include "IThread.hpp"
#include "ITimerManager.hpp"


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <XML configuration file>" << std::endl;
        return 1;
    }
/*
    try {
        // Initialize FactoryManager with XML configuration file
        FactoryManager factoryManager;
        factoryManager.start(argv[1]);

        // Create instances of various classes
        ObjectDictionary* objectDictionary = ObjectDictionary::getInstance();
        IFsm* fsm = (IFsm*)objectDictionary->getObject("fsm_instance");
        auto event = objectDictionary->getObject<IEvent>("event_instance");
        auto state = objectDictionary->getObject<IState>("state_instance");
        auto thread = objectDictionary->getObject<IThread>("thread_instance");
        auto timerManager = objectDictionary->getObject<ITimerManager>("timer_manager_instance");

        // Call the init and start functions for all objects in ObjectDictionary
        objectDictionary->initAllObjects();
        objectDictionary->startAllObjects();

        // Demonstrate usage of various classes
        fsm->processEvent(event);
        thread.start();
        timerManager.tick();

        // Call the stop functions for all objects in ObjectDictionary
        objectDictionary.stopAllObjects();

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
*/
    return 0;
}
