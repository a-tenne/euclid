#!/bin/sh

cmake -S . -B build -G "Unix Makefiles"
cd build
make