cmake_minimum_required(VERSION 3.15)
project(NAND-CHAOS VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_library(nand_core INTERFACE)
target_include_directories(nand_core INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(nand_gates INTERFACE)
target_include_directories(nand_gates INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/gates
)
target_link_libraries(nand_gates INTERFACE nand_core)

add_executable(test_gates tests/test_gates.cpp)
target_link_libraries(test_gates PRIVATE nand_gates)

add_executable(myapp 
    src/main.cpp
)
target_link_libraries(myapp PRIVATE nand_gates)

enable_testing()
add_test(NAME GatesTest COMMAND test_gates)

add_custom_target(run_all
    COMMAND ${CMAKE_COMMAND} -E echo "=========================================="
    COMMAND ${CMAKE_COMMAND} -E echo "          Running Tests First..."
    COMMAND ${CMAKE_COMMAND} -E echo "=========================================="
    COMMAND test_gates
    COMMAND ${CMAKE_COMMAND} -E echo ""
    COMMAND ${CMAKE_COMMAND} -E echo "=========================================="
    COMMAND ${CMAKE_COMMAND} -E echo "          Running Main Application..."
    COMMAND ${CMAKE_COMMAND} -E echo "=========================================="
    COMMAND myapp
    DEPENDS test_gates myapp
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running tests and then main application..."
)
