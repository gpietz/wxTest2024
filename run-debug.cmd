@echo off
mkdir build
cd build
cmake ..
cmake --build . --config Debug
.\Debug\wxTest2024_2.exe
cd ..
