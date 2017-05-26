#!/usr/bin/env sh

echo "[Clean] GOBject_Builder"

if [ -d gob/gen ]; then
	echo "[Clean] Remove 'gob/gen' directory"
	rm -r gob/gen
fi