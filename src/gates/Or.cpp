#include "../../include/gates/Or.hpp"

namespace nandchaos{
    Or::Or() : Component(2, 1, "Or") {}

    void Or::evaluate(){
        invert_a.setInput(0, inputs[0]);
        invert_b.setInput(0, inputs[1]);
        invert_a.evaluate();
        invert_b.evaluate();

        nand.setInput(0, invert_a.getOutput(0));
        nand.setInput(1, invert_b.getOutput(0));
        nand.evaluate();

        outputs[0] = nand.getOutput(0);
    }
}