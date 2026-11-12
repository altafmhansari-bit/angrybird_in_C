#!/bin/bash

mkdir -p build 
echo "Compiling your game sir"

if /c/msys64/ucrt64/bin/gcc.exe src/main.c -o build/game.exe \ -l/c/msys64/ucrt64/inlcude \ -L/c/msys64/ucrt64/lib \
-lraylib -lopengl32 -lgdi32 -lwinmm 
then 
echo "Compilation done sir"
./build/game.exe
else 
echo "Compilation failed"
fi