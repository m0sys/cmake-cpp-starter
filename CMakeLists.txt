cmake_minimum_required(VERSION 3.17) # v3.17 enables ninja multi-config gen
project(cmake_cpp_starter LANGUAGES CXX)

# Define build types i.e. Debug|Release.
add_executable(my_app main.cc)
add_executable(my_app_debug main.cc)
