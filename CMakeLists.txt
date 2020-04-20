project(ray_tracer_challenge)
cmake_minimum_required(VERSION 3.12)

add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)

add_library(project_warnings INTERFACE)
include(cmake/CompilerWarnings.cmake)
set_compiler_warnings(project_warnings)

include_directories(include/rtc)
add_executable(intro src/main.cpp src/vec.cpp)
target_link_libraries(intro PRIVATE project_options project_warnings)
