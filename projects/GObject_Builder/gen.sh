#!/usr/bin/env sh

echo "[Gen] GOBject_Builder"

GOB2=$(which gob2)                   # USE THIS COMMAND TO SEARCH FOR THE RELATIVE PATH
GOB2_SOURCE=gob/test.gob
GOB2_GENDIR=gob/gen

if [ ! -e $GOB2 ]; then             # CHECK IF THE FILE EXISTS
    echo "[Gen] $GOB2 doest not exist (not present in PATH)."
    exit 1                           # EXIT THE PROGRAM IF IT DOES NOT
fi

if [ ! -f $GOB2_SOURCE ]; then
	echo "[Gen] $GOB2_SOURCE doesn't exist !"
	exit 1
fi

if [ ! -d $GOB2_GENDIR ]; then
	echo "[Gen] create directory: $GOB2_GENDIR"
	mkdir -p $GOB2_GENDIR
fi

echo "[Gen] Generate sources files from $GOB2_SOURCE ..."
$GOB2 $GOB2_SOURCE --output-dir $GOB2_GENDIR