#!/usr/bin/env sh

# GObject_Builder
cd projects/GObject_Builder/
./clean.sh
cd -

if [ -d build ]; then
	echo "[Clean] Delete directory: build/"
	rm -r build/
fi