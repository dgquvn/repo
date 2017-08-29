#include_directories()

set(FizzBuzz_classes_SRCS
   Controller.cpp
   inputProperties.cpp
   variables.cpp
   OutputGenerator.cpp
   FileWriter.cpp
)

SET(LIB_TYPE STATIC)

add_library(FizzBuzz_classes ${LIB_TYPE} ${FizzBuzz_classes_SRCS})

file (GLOB test_files tests/*.cpp)
add_tests("${test_files}" "${CMAKE_CURRENT_SOURCE_DIR}" "${Boost_LIBRARIES};FizzBuzz_classes")


