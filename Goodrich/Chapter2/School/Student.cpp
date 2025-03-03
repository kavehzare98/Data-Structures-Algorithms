#include "Student.h"

Student::Student(const std::string &nm, const std::string &maj, int year) 
    : Person(nm), major(maj), gradYear(year) {}

std::string Student::getMajor() { return this->major; }

int Student::getGradYear() { return this->gradYear; }

void Student::setMajor(const std::string &maj) { this->major = maj; }

void Student::setGradYear(int year) { this->gradYear = year; }

void Student::print() {
    std::cout << "Name: " << this->getName() << std::endl
              << "Major: " << this->getMajor() << std::endl
              << "Graduation Year: " << this->getGradYear() << std::endl << std::endl;
}
