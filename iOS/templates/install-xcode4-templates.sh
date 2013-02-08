#!/bin/bash

# base dir
DST_DIR="$HOME/Library/Developer/Xcode/Templates/iOS/WiEngine"

# copy files recursively
copy_files() {
	cp -RP "$1" "$2"
}

# ensure destination dir is existent
check_dst_dir() {
	if [[ -d $DST_DIR ]]; then
		rm -rf "${DST_DIR}"
	fi

	mkdir -p "$DST_DIR"
}

check_dst_dir
for i in Xcode4/* 
do
	copy_files "$i" $DST_DIR
done