#include <iostream>
#include "src.hpp"

int main() {
    int **p = nullptr;

    // Test 1: Basic functionality
    std::cout << "Test 1: Basic functionality" << std::endl;
    Init(p, 3);

    // Add elements to vector 1
    Add_element(p, 1, 10);
    Add_element(p, 1, 20);
    Add_element(p, 1, 30);

    // Add elements to vector 2
    Add_element(p, 2, 100);
    Add_element(p, 2, 200);

    // Get elements
    std::cout << "Vector 1, element 1: " << Get_element(p, 1, 1) << " (expected 10)" << std::endl;
    std::cout << "Vector 1, element 2: " << Get_element(p, 1, 2) << " (expected 20)" << std::endl;
    std::cout << "Vector 1, element 3: " << Get_element(p, 1, 3) << " (expected 30)" << std::endl;
    std::cout << "Vector 2, element 1: " << Get_element(p, 2, 1) << " (expected 100)" << std::endl;
    std::cout << "Vector 2, element 2: " << Get_element(p, 2, 2) << " (expected 200)" << std::endl;

    Clear(p, 3);

    std::cout << "Test 1 passed!" << std::endl;

    return 0;
}
