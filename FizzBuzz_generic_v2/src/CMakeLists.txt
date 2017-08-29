set(FizzBuzz_class_dir
  ${CMAKE_CURRENT_SOURCE_DIR}/FizzBuzz_classes)

include_directories(${FizzBuzz_class_dir})
add_subdirectory(FizzBuzz_classes)

add_executable(Fizz_Buzz_v2 FizzBuzz_main.cpp)

target_link_libraries(Fizz_Buzz_v2 FizzBuzz_classes)
