#pragma once
#include "../core/Component.hpp"

namespace nandchaos
{
    class Nand : public Component
    {
        public:
            Nand() : Component(2, 1, "Nand") {}
            void evaluate() override
            {
                /*
                NAND truth table from the game:
                 a | b | output
                 0 | 0 |   1
                 0 | 1 |   1
                 1 | 0 |   1
                 1 | 1 |   0
                */
                outputs[0] = !(inputs[0] && inputs[1]);
            }
    };
}