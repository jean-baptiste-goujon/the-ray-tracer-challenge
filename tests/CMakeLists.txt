project(tests)
cmake_minimum_required(VERSION 3.12)

include_directories(../include/ lib/catch2/src/)

add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)

add_library(vec STATIC ../src/vec)

add_subdirectory(lib/catch2)

add_executable(tests_vec tests tests_vec_operations)
target_link_libraries(tests_vec PRIVATE project_options vec Catch2::Catch2WithMain)
