#include_directories()

file(GLOB HEADERS *.h)
file(GLOB SRC *.cpp)

SET(LIB_TYPE STATIC)

add_library(FizzBuzz_classes ${LIB_TYPE} ${SRC})

file (GLOB test_files tests/*.cpp)
add_tests("${test_files}" "${CMAKE_CURRENT_SOURCE_DIR}" "${Boost_LIBRARIES};FizzBuzz_classes")


