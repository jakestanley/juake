#!/usr/bin/env sh

mkdir -p bin
gcc display.h main.c -o bin/juake -lglut -lGL
