#!/bin/sh

cmake -S . -B build/build_release
cmake --build build/build_release  --config Release --target my_app
