#include "Person.h"

class Student: public Person {
private:
    std::string major;
    int gradYear;
public:
    Student(const std::string &nm, const std::string &maj, int year);
    // getters
    std::string getMajor();
    int getGradYear();
    // setters
    void setMajor(const std::string &maj);
    void setGradYear(int year);
    // other
    virtual void print();
};
