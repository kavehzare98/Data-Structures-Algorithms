#include "ArrayStack.h"
#include <iostream>
using namespace std;

int main()
{
    ArrayStack<int> A;
    A.push(7);
    A.push(13);
    cout << "Top: " << A.top() << endl;
    A.pop();
    A.push(9);
    cout << "Top: " << A.top() << endl;
    A.pop();
    ArrayStack<string> B(10);

    B.push("Bob");
    B.push("Alice");
    cout << B.top() << endl;
    B.pop();
    B.push("Eve");
    return EXIT_SUCCESS;
}
