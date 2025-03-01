cmake_minimum_required(VERSION 3.10)
project(learn_you_some_cpp CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
include_directories(test)

add_library(learn_you_some_cpp
  src/0_greet.cc
  src/1_basic_math.cc
  src/2_basic_strings.cc
  # Add more source files here
)

add_executable(run_tests
  test/0_test_greet.cc
  test/1_test_basic_math.cc
  test/2_test_basic_strings.cc
  # Add more test files here
)

target_link_libraries(run_tests PRIVATE learn_you_some_cpp)


enable_testing()
add_test(NAME all_tests COMMAND run_tests) 
