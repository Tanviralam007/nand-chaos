#pragma once

#include <vector>
#include <string>
#include <stdexcept>

namespace nandchaos
{
    class Component
    {
        protected:
            std::vector<bool> inputs;
            std::vector<bool> outputs;
            std::string name;
        
        public:
            Component(size_t numInputs, size_t numOutputs, const std::string& componentName = "Component")
            {
                inputs = std::vector<bool>(numInputs, false);
                outputs = std::vector<bool>(numOutputs, false);
                name = componentName;
            }

            virtual ~Component(){}
            virtual void evaluate() = 0;

            // input output management
            virtual void setInput(size_t index, bool value)
            {
                if(index >= inputs.size())
                {
                    throw std::out_of_range("Input index out of range");
                }
                inputs[index] = value;
            }

            virtual bool getOutput(size_t index) const
            {
                if(index >= outputs.size())
                {
                    throw std::out_of_range("Output index out of range");
                }
                return outputs[index];
            }

            virtual void setInputs(const std::vector<bool>& values)
            {
                if(values.size() != inputs.size())
                {
                    throw std::invalid_argument("Number of input values must match the number of inputs");
                }
                inputs = values;
            }

            size_t getInputCount() const
            {
                return inputs.size();
            }

            size_t getOutputCount() const
            {
                return outputs.size();
            }

            const std::string& getName() const
            {
                return name;
            }
    };
}