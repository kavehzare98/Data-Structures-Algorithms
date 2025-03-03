#include "Progression.h"
#include <iostream>

// Generic Progression
void Progression::printProgression(int n) {
    std::cout << firstValue();
    for (int i = 2; i <= n; i++) 
         std::cout << ' ' << nextValue();
    std::cout << std::endl;
}

long Progression::firstValue() {
    cur = first;
    return cur;
}

long Progression::nextValue() {
    return ++cur;
}
// End of generic Progression class



// Arithmetic Progression
ArithProgression::ArithProgression(long i)
    : Progression(), inc(i) { }

long ArithProgression::nextValue() {
    cur += inc;
    return cur;
}
// End of Arithmetic Progression class



// Geometric Progression
GeoProgression::GeoProgression(long b)
    : Progression(1), 
    base(b) { }

long GeoProgression::nextValue() {
    cur *= base;
    return cur;
}
// End of Geometric Progression class



// Fibonacci Progression Class
FiboProgression::FiboProgression(long f, long s)
    : Progression(f), 
    second(s), 
    prev(second - first) { }

long FiboProgression::firstValue() {
    cur = first;
    prev = second - first;
    return cur;
}

long FiboProgression::nextValue() {
    long temp = prev;
    prev = cur;
    cur += temp;
    return cur;
}
// End of Fibonacci Progression Class
