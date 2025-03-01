cmake_minimum_required(VERSION 3.10)
project(learn_you_some_cpp CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
include_directories(test)

add_library(learn_you_some_cpp
  src/00_greet.cc
  src/01_basic_math.cc
  src/02_basic_strings.cc
  src/03_basic_chars.cc
  src/04_control_flow.cc
  src/05_basic_functions.cc
  src/06_arrays_and_memory_basics.cc
  src/07_pointers_and_references.cc
  src/08_dynamic_memory.cc
  src/09_bitwise.cc
  src/10_algorithm_basics.cc
  # Add more source files here
)

add_executable(run_tests
  test/00_test_greet.cc
  test/01_test_basic_math.cc
  test/02_test_basic_strings.cc
  test/03_test_basic_chars.cc
  test/04_test_control_flow.cc
  test/05_test_basic_functions.cc
  test/06_test_arrays_and_memory_basics.cc
  test/07_test_pointers_and_references.cc
  test/08_test_dynamic_memory.cc
  test/09_test_bitwise.cc
  test/10_test_algorithm_basics.cc
  # Add more test files here
)

target_link_libraries(run_tests PRIVATE learn_you_some_cpp)


enable_testing()
add_test(NAME all_tests COMMAND run_tests) 
