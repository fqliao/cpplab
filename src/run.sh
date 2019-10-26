#!/bin/bash

set -e

dirpath="$(cd "$(dirname "$0")" && pwd)"
cd $dirpath

cd build
cmake ..
make
./cpplab

