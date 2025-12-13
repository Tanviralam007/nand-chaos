#include "../../include/gates/Invert.hpp"

namespace nandchaos
{
    Invert::Invert() : Component(1, 1, "Invert"), nand() {}
    void Invert::evaluate()
    {
        nand.setInput(0, inputs[0]);
        nand.setInput(1, inputs[0]);
        nand.evaluate();
        outputs[0] = nand.getOutput(0);
    }
}