#include "../../include/gates/Xor.hpp"

namespace nandchaos
{
    Xor::Xor() : Component(2, 1, "Xor") {}

    void Xor::evaluate(){
        invert_a.setInput(0, inputs[0]);
        invert_b.setInput(0, inputs[1]);
        invert_a.evaluate();
        invert_b.evaluate();

        and1.setInput(0, inputs[0]);
        and1.setInput(1, invert_b.getOutput(0));
        and1.evaluate();

        and2.setInput(0, invert_a.getOutput(0));
        and2.setInput(1, inputs[1]);
        and2.evaluate();

        or_gate.setInput(0, and1.getOutput(0));
        or_gate.setInput(1, and2.getOutput(0));
        or_gate.evaluate();

        outputs[0] = or_gate.getOutput(0);
    }
}