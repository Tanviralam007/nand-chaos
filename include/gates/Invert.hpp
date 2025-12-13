#pragma once
#include "../core/Component.hpp"
#include "Nand.hpp"

namespace nandchaos
{
    class Invert : public Component
    {
        private:
            Nand nand;
        public:
            Invert();
            void evaluate() override;
    };
}