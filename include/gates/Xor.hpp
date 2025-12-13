#pragma once
#include "../include/core/Component.hpp"
#include "Invert.hpp"
#include "And.hpp"
#include "Or.hpp"

namespace nandchaos
{
    class Xor : public Component
    {
        private:
            Invert invert_a;
            Invert invert_b;
            And and1;
            And and2;
            Or or_gate;
        public:
            Xor();
            void evaluate() override;
    };
}