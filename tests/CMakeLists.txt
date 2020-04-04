cmake_minimum_required(VERSION 3.12)
project(tests)

add_executable(tests tests.cpp)
target_include_directories(tests PRIVATE ../include/)
