@echo off
mkdir build
cd build
cmake ..
cmake --build . --config Release
.\Debug\wxTest2024_2.exe
cd ..
