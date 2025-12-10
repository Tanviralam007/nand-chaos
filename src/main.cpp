#include <iostream>
#include "../include/gates/Nand.hpp"

using namespace nandchaos;

int main(int argc, char** argv){
    std::cout << "level 0: NAND Gates Demonstration\n" << std::endl;

    Nand nand;

    std::cout << "truth table for NAND gate:" << std::endl;
    std::cout << "a | b | output" << std::endl;
    std::cout << "--|---|--------" << std::endl;

    for(int a = 0; a <= 1; a++){
        for(int b = 0; b <= 1; b++){
            nand.setInput(0, a);
            nand.setInput(1, b);
            nand.evaluate();
            std::cout << a << " | " << b << " | " << nand.getOutput(0) << std::endl;
        }
    }

    return 0;
}