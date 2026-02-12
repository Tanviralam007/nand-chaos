#include "../../include/arithmetic/MultiBitAdder.hpp"

namespace nandchaos
{
    MultiBitAdder::MultiBitAdder(size_t bitWidth) 
    : Component(bitWidth * 2 + 1, bitWidth + 1, "MultiBitAdder"), bitWidth(bitWidth)
    {
        // input: bits for A, bits for B, 1 carry_in
        // output: bits for sum, 1 carry_out

        fullAdders.resize(bitWidth);
    }

    void MultiBitAdder::evaluate()
    {
        // initial carry_in
        bool carry = inputs[bitWidth * 2];

        // process each bit position from lsb to msb
        for (size_t i = 0; i < bitWidth; ++i)
        {
            // set input for this bit positions
            fullAdders[i].setInput(0, inputs[i]);
            fullAdders[i].setInput(1, inputs[i + bitWidth]);
            fullAdders[i].setInput(2, carry);

            // evaluate this adder
            fullAdders[i].evaluate();
            
            // store sum bit
            outputs[i] = fullAdders[i].getSum();

            // propagate carry to next stage
            carry = fullAdders[i].getCarry();
            
        }

        // final carry out
        outputs[bitWidth] = carry;
    }

    void MultiBitAdder::setA(const std::vector<bool>& a)
    {
        if(a.size() != bitWidth)
        {
            throw std::invalid_argument("Input A size does not match bit width");
        }
        for (size_t i = 0; i < bitWidth; ++i)
        {
            inputs[i] = a[i];
        }
    }

    void MultiBitAdder::setB(const std::vector<bool>& b)
    {
        if(b.size() != bitWidth)
        {
            throw std::invalid_argument("Input B size does not match bit width");
        }
        for (size_t i = 0; i < bitWidth; ++i)
        {
            inputs[i + bitWidth] = b[i];
        }
    }

    void MultiBitAdder::setCarryIn(bool carryIn)
    {
        inputs[bitWidth * 2] = carryIn;
    }

    std::vector<bool> MultiBitAdder::getSum() const
    {
        std::vector<bool> sum(bitWidth);
        for (size_t i = 0; i < bitWidth; ++i)
        {
            sum[i] = outputs[i];
        }
        return sum;
    }

    bool MultiBitAdder::getCarryOut() const
    {
        return outputs[bitWidth];
    }
}