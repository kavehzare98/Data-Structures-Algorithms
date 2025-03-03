#include "Person.h"

Person::Person(const std::string &nm) : name(nm) { }

std::string Person::getName() { return this->name; }

void Person::setName(const std::string &nm) { this->name = nm; }

void Person::print() {
    std::cout << "Name: " << this->name << std::endl;
}
