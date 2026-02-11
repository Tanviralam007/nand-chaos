#include "../../include/arithmetic/FullAdder.hpp"

namespace nandchaos
{
    FullAdder::FullAdder() : Component(3, 2, "FullAdder")
    {
        // 3 input: a, b, cin
        // 2 output: sum, carry
    };

    void FullAdder::evaluate()
    {
        // first half adder: add a and b
        halfAdder1.setInput(0, inputs[0]); // a
        halfAdder1.setInput(1, inputs[1]); // b
        halfAdder1.evaluate();
        
        bool intermediateSum = halfAdder1.getSum();
        bool carry1 = halfAdder1.getCarry();

        // second half adder: add intermediate sum and carry_in
        halfAdder2.setInput(0, intermediateSum); 
        halfAdder2.setInput(1, inputs[2]); // carry_in
        halfAdder2.evaluate();

        outputs[0] = halfAdder2.getSum(); // final sum
        bool carry2 = halfAdder2.getCarry();

        // or gate: combine both carries
        orGate.setInput(0, carry1);
        orGate.setInput(1, carry2);
        orGate.evaluate();

        outputs[1] = orGate.getOutput(0); // final carry_out
    }
}