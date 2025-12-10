# nand-chaos
a simulation game for my baby boy

NAND-CHAOS/
├── include/
│   ├── core/
│   │   ├── Component.hpp          # Base abstract class
│   │   ├── Pin.hpp                # Input/Output pins
│   │   ├── Wire.hpp               # Connections
│   │   └── Circuit.hpp            # Simulation engine
│   │
│   ├── gates/                     
│   │   ├── Nand.hpp               
│   │   ├── Invert.hpp
│   │   ├── And.hpp
│   │   ├── Or.hpp
│   │   └── Xor.hpp
│   │
│   ├── arithmetic/                # Level 1: Arithmetics
│   │   ├── HalfAdder.hpp
│   │   ├── FullAdder.hpp
│   │   ├── MultiBitAdder.hpp
│   │   ├── Increment.hpp
│   │   ├── Subtraction.hpp
│   │   ├── EqualToZero.hpp
│   │   └── LessThanZero.hpp
│   │
│   ├── switching/                 # Level 2: Switching/Plumbing
│   │   ├── Selector.hpp           
│   │   └── Switch.hpp             
│   │
│   ├── alu/                       # Level 3: Arithmetic Logic Unit
│   │   ├── LogicUnit.hpp          
│   │   ├── ArithmeticUnit.hpp
│   │   ├── ALU.hpp
│   │   └── Condition.hpp
│   │
│   ├── memory/                    # Level 4: Memory
│   │   ├── SRLatch.hpp
│   │   ├── DataFlipFlop.hpp       
│   │   ├── Register.hpp
│   │   ├── Counter.hpp
│   │   └── RAM.hpp
│   │
│   └── processor/                 # Level 5: Processor
│       ├── CombinedMemory.hpp
│       ├── InstructionDecoder.hpp 
│       ├── ControlUnit.hpp        
│       ├── Computer.hpp
│       └── InputOutput.hpp
│
├── src/                           
│   ├── core/
│   ├── gates/
│   ├── arithmetic/
│   ├── switching/
│   ├── alu/
│   ├── memory/
│   └── processor/
│
├── tests/                         # Unit tests per component
├── examples/                      
│   └── main.cpp                   
├── docs/                          # Documentation              
└── CMakeLists.txt
