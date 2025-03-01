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
  src/11_stl_containers.cc
  src/12_stl_algorithms.cc
  src/17_recursion.cc
  src/18_recursion_collections.cc
  src/19_backtracking.cc
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
  test/11_test_stl_containers.cc
  test/12_test_stl_algorithms.cc
  test/13_test_custom_vectors.cc
  test/14_test_singly_linked_list.cc
  test/15_test_doubly_linked_list.cc
  test/16_test_linked_list_algorithms.cc
  test/17_test_recursion.cc
  test/18_test_recursion_collections.cc
  test/19_test_backtracking.cc
  # Add more test files here
)

target_link_libraries(run_tests PRIVATE learn_you_some_cpp)


enable_testing()
add_test(NAME all_tests COMMAND run_tests) 
