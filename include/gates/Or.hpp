#pragma once
#include "../include/core/Component.hpp"
#include "Nand.hpp"
#include "Invert.hpp"

namespace nandchaos
{
    class Or : public Component
    {
        private:
            Invert invert_a;
            Invert invert_b;
            Nand nand;
        public:
            Or();
            void evaluate() override;
    };
}