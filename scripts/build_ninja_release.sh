#!/bin/sh

cmake -G "Ninja" -S . -B build/build_ninja_release
cmake --build build/build_ninja_release  --config Release --target my_app
