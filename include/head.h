#ifndef HEAD_H
#define HEAD_H

#include<iostream>
#include<string>
#include<map>

#define DELCARE_CLASS(classname) \
public: \
    static classname* create##classname(){  \
        return new classname;   \
    } \
    static Action act; 

#define REGISTER_CLASS(classname) \
Action classname::act = Action(#classname, (BasePtr)create##classname);

#define REGISTRY(classname) Registry::getInstance().get(#classname);


class Base;

typedef void* (*BasePtr)();

class Registry{
private:
    std::map<std::string, BasePtr> mMap;
    Registry() = default;

public:
    Base* get(const std::string& name);
    void registre(const std::string& name, BasePtr classname);
    static Registry& getInstance();

};

class Action{
public:
    Action(){}
    Action(const std::string& name, BasePtr classname){
        Registry::getInstance().registre(name, classname);
    }
};

class Base{
public:
    Base() = default;
};

class A: public Base{
public:
    A(): Base(){std::cout << "I am A constructor..." << std::endl;}
    DELCARE_CLASS(A)
};
REGISTER_CLASS(A)

class B: public Base{
public:
    B(): Base(){std::cout << "I am B constructor..." << std::endl;}
    DELCARE_CLASS(B)
};
REGISTER_CLASS(B)

class C: public Base{
public:
    C(): Base(){std::cout << "I am C constrctor..." << std::endl;}
    DELCARE_CLASS(C)
};
REGISTER_CLASS(C)


#endif