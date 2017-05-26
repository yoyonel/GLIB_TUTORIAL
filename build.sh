#!/usr/bin/env sh

# GObject_Builder
cd projects/GObject_Builder/
./gen.sh
cd -

mkdir -p build
cd build
cmake ..
make -j
cd -