#!/bin/bash

if [[ "$EUID" -ne 0 ]]
  then echo "Please run as root! (sudo ./build_all.sh)"
  exit
fi

rm -rf build/
mkdir build/
cmake -S . -B build/
cmake --build build/ --parallel
cmake --install build/
rm -rf build/
