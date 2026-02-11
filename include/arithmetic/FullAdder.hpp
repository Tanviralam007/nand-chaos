#pragma once
#include "../core/Component.hpp"
#include "HalfAdder.hpp"
#include "../gates/Or.hpp"

namespace nandchaos
{
    class FullAdder : public Component
    {
        private:
            HalfAdder halfAdder1;
            HalfAdder halfAdder2;
            Or orGate;
        public:
            FullAdder();
            void evaluate() override;

            // helper methods
            bool getSum() const{return outputs[0];}
            bool getCarry() const{return outputs[1];}
            
    };
}