cmake_minimum_required(VERSION 2.6)
project(Fizz_Buzz_v2)

# Disable in-source builds to keep the tree pristinecd
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

# Add custom CMake Modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules")

# Include the testing framework
include(tests)

configure_file("${CMAKE_SOURCE_DIR}/cmake/FizzBuzz_config.hpp.in" "${CMAKE_BINARY_DIR}/FizzBuzz_config.hpp")

# Setup Doxygen
find_package(Doxygen)
if(DOXYGEN_FOUND)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.cmake ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
  add_custom_target(doc ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} COMMENT "Generating API documentation with Doxygen" 
    VERBATIM)
endif(DOXYGEN_FOUND)

include_directories(${CMAKE_BINARY_DIR})

add_subdirectory(src)

