cmake_minimum_required(VERSION 3.10)
project(learn_you_some_cpp CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
include_directories(test)

add_library(learn_you_some_cpp
  src/greet.cpp
  # Add more source files here
)

add_executable(run_tests
  test/test_greet.cpp
  # Add more test files here
)

target_link_libraries(run_tests PRIVATE learn_you_some_cpp)


enable_testing()
add_test(NAME all_tests COMMAND run_tests) 
