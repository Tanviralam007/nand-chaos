#pragma once
#include "../core/Component.hpp"
#include "../gates/Xor.hpp"
#include "../gates/And.hpp"

namespace nandchaos
{
    class HalfAdder : public Component{
        private:
            Xor xorGate;
            And andGate;
        public:
            HalfAdder();
            void evaluate() override;

            // helper methods
            bool getSum() const{return outputs[0];}
            bool getCarry() const{return outputs[1];}
    };
}