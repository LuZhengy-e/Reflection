#include "head.h"

Registry& Registry::getInstance(){
    static Registry registry;
    return registry;
}

Base* Registry::get(const std::string& name){
    std::map<std::string, BasePtr>::iterator it = mMap.find(name);
    if(it == mMap.end()){
        std::cerr << name << " has not been registered..." << std::endl;
        return nullptr;
    }

    return static_cast<Base*>(it->second()); // callback function
}

void Registry::registre(const std::string& name, BasePtr classname){
    mMap.insert(std::pair<std::string, BasePtr>(name, classname));
}
