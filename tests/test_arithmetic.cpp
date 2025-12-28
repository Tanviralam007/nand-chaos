#include <iostream>
#include <cassert>
#include "../include/arithmetic/HalfAdder.hpp"

using namespace nandchaos;

void test_half_adder() {
    std::cout << "Testing Half Adder..." << std::endl;
    HalfAdder halfAdder;

    // Test case 1: 0 + 0 = 0 (sum = 0, carry = 0)
    halfAdder.setInput(0, false);
    halfAdder.setInput(1, false);
    halfAdder.evaluate();
    assert(halfAdder.getSum() == false);
    assert(halfAdder.getCarry() == false);
    std::cout << "0 + 0 = 0 (sum=0, carry=0)" << std::endl;

    // Test case 2: 0 + 1 = 1 (sum = 1, carry = 0)
    halfAdder.setInput(0, false);
    halfAdder.setInput(1, true);
    halfAdder.evaluate();
    assert(halfAdder.getSum() == true);
    assert(halfAdder.getCarry() == false);
    std::cout << "0 + 1 = 1 (sum=1, carry=0)" << std::endl;

    // Test case 3: 1 + 0 = 1 (sum = 1, carry = 0)
    halfAdder.setInput(0, true);
    halfAdder.setInput(1, false);
    halfAdder.evaluate();
    assert(halfAdder.getSum() == true);
    assert(halfAdder.getCarry() == false);
    std::cout << "1 + 0 = 1 (sum=1, carry=0)" << std::endl;

    // Test case 4: 1 + 1 = 0 (sum = 0, carry = 1)
    halfAdder.setInput(0, true);
    halfAdder.setInput(1, true);
    halfAdder.evaluate();
    assert(halfAdder.getSum() == false);
    assert(halfAdder.getCarry() == true);
    std::cout << "1 + 1 = 0 (sum=0, carry=1)" << std::endl << std::endl;
    
    std::cout << "All Half Adder tests passed!\n" << std::endl;
}

int main() {
    test_half_adder();
    return 0;
}   