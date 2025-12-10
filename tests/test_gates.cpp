#include <iostream>
#include <cassert>
#include "../../include/gates/Nand.hpp"

using namespace nandchaos;

void test_nand_gates(){
    Nand nand;

    // testcase1: 0 | 0 -> 1
    nand.setInput(0, false);
    nand.setInput(1, false);
    nand.evaluate();
    assert(nand.getOutput(0) == true);
    std::cout << "nand(0, 0) = " << nand.getOutput(0) << std::endl;

    // testcase2: 0 | 1 -> 1
    nand.setInput(0, false);
    nand.setInput(1, true);
    nand.evaluate();
    assert(nand.getOutput(0) == true);
    std::cout << "nand(0, 1) = " << nand.getOutput(0) << std::endl;

    // testcase3: 1 | 0 -> 1
    nand.setInput(0, true);
    nand.setInput(1, false);
    nand.evaluate();
    assert(nand.getOutput(0) == true);
    std::cout << "nand(1, 0) = " << nand.getOutput(0) << std::endl;

    // testcase4: 1 | 1 -> 0
    nand.setInput(0, true);
    nand.setInput(1, true);
    nand.evaluate();
    assert(nand.getOutput(0) == false);
    std::cout << "nand(1, 1) = " << nand.getOutput(0) << std::endl;
}

int main(){
    test_nand_gates();
    return 0;   
}