#include <iostream>

void myFunc();

int main() {
  myFunc();
  std::cout << "Hello World" << std::endl;
  return 0;
}

void myFunc() {
  int a = 5;
  int b = 6;
  int c;
  c = a * b;
  a = c + a;
  b = b - c;
  c = b;
}
