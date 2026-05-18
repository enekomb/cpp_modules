#include "Array.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int main()
{
    const unsigned int SIZE = 10;

    // Create an Array of int
    Array<int> numbers(SIZE);
    srand(time(NULL));
    for (unsigned int i = 0; i < SIZE; i++)
        numbers[i] = rand() % 100;

    std::cout << "Original numbers array:" << std::endl;
    for (unsigned int i = 0; i < SIZE; i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;

    // Test copy constructor
    Array<int> copy(numbers);
    copy[0] = -1; // Modify copy to ensure deep copy

    std::cout << "After modifying copy[0]:" << std::endl;
    std::cout << "Original numbers[0]: " << numbers[0] << std::endl;
    std::cout << "Copy numbers[0]: " << copy[0] << std::endl;

    // Test assignment operator
    Array<int> assigned;
    assigned = numbers;
    assigned[1] = -2;

    std::cout << "After modifying assigned[1]:" << std::endl;
    std::cout << "Original numbers[1]: " << numbers[1] << std::endl;
    std::cout << "Assigned numbers[1]: " << assigned[1] << std::endl;

    // Test out-of-bounds
    try {
        numbers[SIZE] = 0; // index equal to size
    } catch (const std::exception &e) {
        std::cout << "Caught exception (index SIZE): " << e.what() << std::endl;
    }

    try {
        // numbers[-1] = 0;  // Cannot use negative index with unsigned int
    } catch (const std::exception &e) {
        std::cout << "Caught exception (negative index): " << e.what() << std::endl;
    }

    // Test Array of strings
    Array<std::string> words(3);
    words[0] = "hello";
    words[1] = "world";
    words[2] = "!";

    std::cout << "Words array:" << std::endl;
    for (unsigned int i = 0; i < words.size(); i++)
        std::cout << words[i] << " ";
    std::cout << std::endl;

    return 0;
}
