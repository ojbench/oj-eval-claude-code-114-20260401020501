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

    // Test 2: Test capacity expansion
    std::cout << "\nTest 2: Capacity expansion test" << std::endl;
    p = nullptr;
    Init(p, 1);

    // Add many elements to test capacity doubling
    for(int i = 1; i <= 20; i++){
        Add_element(p, 1, i * 10);
    }

    std::cout << "Added 20 elements" << std::endl;

    // Verify all elements
    bool allCorrect = true;
    for(int i = 1; i <= 20; i++){
        int val = Get_element(p, 1, i);
        if(val != i * 10){
            std::cout << "Error: element " << i << " is " << val << ", expected " << (i * 10) << std::endl;
            allCorrect = false;
        }
    }

    if(allCorrect){
        std::cout << "All 20 elements are correct!" << std::endl;
    }

    Clear(p, 1);
    std::cout << "Test 2 passed!" << std::endl;

    return 0;
}
