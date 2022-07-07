#!/bin/sh

cmake -G Ninja -DCMAKE_BUILD_TYPE:STRING=Debug -S . -B build/build_ninja_debug
cmake --build build/build_ninja_debug --target my_app_debug
