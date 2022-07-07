#!/bin/sh

cmake -G Ninja -DCMAKE_BUILD_TYPE:STRING=Release -S . -B build/build_ninja_release
cmake --build build/build_ninja_release  --target my_app
