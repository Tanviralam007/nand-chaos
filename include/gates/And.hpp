#pragma once
#include "../core/Component.hpp"
#include "Nand.hpp"
#include "Invert.hpp"

namespace nandchaos
{
    class And : public Component
    {
        private:
            Nand nand;
            Invert invert;

        public:
            And();
            void evaluate() override;
    };
}