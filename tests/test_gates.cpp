#include <iostream>
#include <cassert>
#include "../include/gates/Xor.hpp"

using namespace nandchaos;

void test() {
    std::cout << "Testing XOR Gate..." << std::endl;
    Xor xorGate;
    
    // Test case 1: 0, 0 -> 0
    xorGate.setInput(0, false);
    xorGate.setInput(1, false);
    xorGate.evaluate();
    assert(xorGate.getOutput(0) == false);
    std::cout << "xor(0, 0) = 0" << std::endl;
    
    // Test case 2: 0, 1 -> 1
    xorGate.setInput(0, false);
    xorGate.setInput(1, true);
    xorGate.evaluate();
    assert(xorGate.getOutput(0) == true);
    std::cout << "xor(0, 1) = 1" << std::endl;
    
    // Test case 3: 1, 0 -> 1
    xorGate.setInput(0, true);
    xorGate.setInput(1, false);
    xorGate.evaluate();
    assert(xorGate.getOutput(0) == true);
    std::cout << "xor(1, 0) = 1" << std::endl;
    
    // Test case 4: 1, 1 -> 0
    xorGate.setInput(0, true);
    xorGate.setInput(1, true);
    xorGate.evaluate();
    assert(xorGate.getOutput(0) == false);
    std::cout << "xor(1, 1) = 0" << std::endl;
    
    std::cout << "All XOR gate tests passed!\n" << std::endl;
}

int main(){
    test();
    
    return 0;   
}