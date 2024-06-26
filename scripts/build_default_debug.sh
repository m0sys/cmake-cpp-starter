#!/bin/sh

# Config opt will only work for multi-config generators such as XCode.
# Use the ninja generator for single-config gen alt - cross platform.
cmake -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -S . -B build/build_debug
cmake --build build/build_debug  --config Debug --target cmake_cpp_starter_my_app cmake_cpp_starter_my_app_test
