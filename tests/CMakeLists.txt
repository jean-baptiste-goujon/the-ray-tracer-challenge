project(tests)
cmake_minimum_required(VERSION 3.12)

include_directories(../include/ ../include/rtc/)

add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)

add_library(vec STATIC ../src/vec)

add_executable(tests_vec tests tests_vec_operations)
target_link_libraries(tests_vec PRIVATE project_options vec)
