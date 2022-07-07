#!/bin/sh

cmake -S . -B build/build_debug
cmake --build build/build_debug  --config Debug --target my_app_debug
