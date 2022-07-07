#!/bin/sh

cmake -G "Ninja" -S . -B build/build_ninja_debug
cmake --build build/build_ninja_debug  --config Debug --target my_app_debug
