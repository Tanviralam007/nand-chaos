#include "../../include/gates/And.hpp"

namespace nandchaos
{
    And::And() : Component(2, 1, "And") {
        
    }

    void And::evaluate()
    {
        nand.setInput(0, inputs[0]);
        nand.setInput(1, inputs[1]);
        nand.evaluate();
        
        invert.setInput(0, nand.getOutput(0));
        invert.evaluate();

        outputs[0] = invert.getOutput(0);
    }
}