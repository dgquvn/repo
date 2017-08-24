cmake_minimum_required(VERSION 2.6)
project(Fizz_Buzz_v2)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules")
include(tests)

set(FizzBuzz_class_dir
  ${CMAKE_CURRENT_SOURCE_DIR}/FizzBuzz_classes)

configure_file("${CMAKE_SOURCE_DIR}/cmake/FizzBuzz_config.hpp.in" "${CMAKE_BINARY_DIR}/FizzBuzz_config.hpp")

include_directories(${CMAKE_BINARY_DIR})
include_directories(${FizzBuzz_class_dir})
add_subdirectory(FizzBuzz_classes)


add_executable(Fizz_Buzz_v2 FizzBuzz_main.cpp)

target_link_libraries(Fizz_Buzz_v2 FizzBuzz_classes)

