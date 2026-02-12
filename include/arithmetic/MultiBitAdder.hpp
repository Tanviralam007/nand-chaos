#pragma once
#include "../core/Component.hpp"
#include "FullAdder.hpp"
#include <vector>

namespace nandchaos
{
    class MultiBitAdder : public Component
    {
        private:
            size_t bitWidth;
            std::vector<FullAdder> fullAdders;
        
        public:
            // constructors will take bit widths
            MultiBitAdder(size_t bitWidth = 16);
            void evaluate() override;

            // helper methods 
            void setA(const std::vector<bool>& a);
            void setB(const std::vector<bool>& b);
            void setCarryIn(bool carryIn);

            std::vector<bool> getSum() const;
            bool getCarryOut() const;
            size_t getBitWidth() const{return bitWidth;}
    };
}