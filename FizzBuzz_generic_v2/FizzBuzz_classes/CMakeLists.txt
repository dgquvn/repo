#include_directories()

set(FizzBuzz_classes_SRCS
   Controller.h Controller.cpp
   inputProperties.h inputProperties.cpp
   variables.h variables.cpp
   generate_output.h generate_output.cpp
   writing_to_file.h writing_to_file.cpp
)

SET(LIB_TYPE STATIC)

add_library(FizzBuzz_classes ${LIB_TYPE} ${FizzBuzz_classes_SRCS})

#file (GLOB test_files tests/*.cpp)
#add_tests("${test_files}" "${CMAKE_CURRENT_SOURCE_DIR}" "${Boost_LIBRARIES}")


