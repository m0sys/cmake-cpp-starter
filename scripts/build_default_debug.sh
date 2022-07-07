#!/bin/sh

# Config opt will only work for multi-config generators such as XCode.
# Use the ninja generator for single-config gen alt - cross platform.
cmake -S . -B build/build_debug
cmake --build build/build_debug  --config Debug --target my_app_debug
