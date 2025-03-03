#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>

class Person {
private:
    std::string name;

public:
    Person(const std::string &nm);
    std::string getName();
    void setName(const std::string &nm);
    virtual void print();
};
#endif
