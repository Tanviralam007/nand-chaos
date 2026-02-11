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
                outputs[0] = !(inputs[0] && inputs[1]);
            }
    };
}