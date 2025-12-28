#include "../../include/arithmetic/HalfAdder.hpp"

namespace nandchaos
{
    HalfAdder::HalfAdder() : Component(2, 2, "HalfAdder")
    {
        // 2 input: a, b
        // 2 output: sum, carry
    }

    void HalfAdder::evaluate()
    {
        // calculte sum
        xorGate.setInput(0, inputs[0]); // a
        xorGate.setInput(1, inputs[1]); // b
        xorGate.evaluate();
        outputs[0] = xorGate.getOutput(0); // sum

        // calculate carry
        andGate.setInput(0, inputs[0]); // a
        andGate.setInput(1, inputs[1]); // b
        andGate.evaluate();
        outputs[1] = andGate.getOutput(0); // carry
    }
}