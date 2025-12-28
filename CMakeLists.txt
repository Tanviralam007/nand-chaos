cmake_minimum_required(VERSION 3.15)
project(NAND-CHAOS VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# Core library
add_library(nand_core INTERFACE)
target_include_directories(nand_core INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Gates interface library
add_library(nand_gates INTERFACE)
target_include_directories(nand_gates INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/gates
)
target_link_libraries(nand_gates INTERFACE nand_core)

# Gates implementation library
add_library(nand_gates_impl
    src/gates/Invert.cpp
    src/gates/And.cpp
    src/gates/Or.cpp
    src/gates/Xor.cpp
)
target_link_libraries(nand_gates_impl PUBLIC nand_gates)

# Arithmetic library
add_library(nand_arithmetic
    src/arithmetic/HalfAdder.cpp
)
target_link_libraries(nand_arithmetic PUBLIC nand_gates_impl)

# Test executables
add_executable(test_gates tests/test_gates.cpp)
target_link_libraries(test_gates PRIVATE nand_gates_impl)

add_executable(test_arithmetic tests/test_arithmetic.cpp)
target_link_libraries(test_arithmetic PRIVATE nand_arithmetic)

# Main application (optional)
add_executable(myapp 
    src/main.cpp
)
target_link_libraries(myapp PRIVATE nand_gates_impl)

# Enable testing
enable_testing()
add_test(NAME GatesTest COMMAND test_gates)
add_test(NAME ArithmeticTest COMMAND test_arithmetic)

# Custom target to run all tests
add_custom_target(run_all
    COMMAND ${CMAKE_COMMAND} -E echo "=========================================="
    COMMAND ${CMAKE_COMMAND} -E echo "          Running Gate Tests..."
    COMMAND ${CMAKE_COMMAND} -E echo "=========================================="
    COMMAND test_gates
    COMMAND ${CMAKE_COMMAND} -E echo ""
    COMMAND ${CMAKE_COMMAND} -E echo "=========================================="
    COMMAND ${CMAKE_COMMAND} -E echo "          Running Arithmetic Tests..."
    COMMAND ${CMAKE_COMMAND} -E echo "=========================================="
    COMMAND test_arithmetic
    DEPENDS test_gates test_arithmetic
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running all tests..."
)
