#include "Progression.h"
#include <iostream>

int main()
{
/*
    int step;
    int count;
    char keepLooping;

    do {

        std::cout << "Would you like to see an arithmetic operation?\t";
        std::cin >> keepLooping;

        if (keepLooping == 'y') {
            std::cout << "What step size would you like? ";
            std::cin >> step;

            ArithProgression aProg(step);

            std::cout << "How many numbers would you like to see?\t";
            std::cin >> count;

            aProg.printProgression(count);
        }


    } while (keepLooping == 'y');
*/

    FiboProgression fibo1(0, 1);
    fibo1.printProgression(10);
    
    return 0;
}
