cmake_minimum_required(VERSION 2.6)
project(Fizz_Buzz_v2)

#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules")
#include(tests)

set(FizzBuzz_class_dir
  ${CMAKE_CURRENT_SOURCE_DIR}/FizzBuzz_classes)

add_subdirectory(FizzBuzz_classes)

include_directories(${FizzBuzz_class_dir})
include_directories(${CMAKE_BINARY_DIR})

add_executable(Fizz_Buzz_v2 FizzBuzz_main.cpp)

target_link_libraries(Fizz_Buzz_v2 FizzBuzz_classes)

