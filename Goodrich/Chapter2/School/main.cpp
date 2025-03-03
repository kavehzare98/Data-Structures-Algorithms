#include "Student.h"
using std::string;

int main()
{
    Person person("Advaith");

    string name = "Kaveh";
    string major = "Computer Science";
    int graduationYear = 2027;

    Student student1(name, major, graduationYear);

    person.print();

    student1.print();
    
    student1.setName("Kevin");

    student1.print();

    return 0;
}
