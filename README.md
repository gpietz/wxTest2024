# wxTest2024
*** 

This is a small test project aimed at exploring the process of creating a C++ project using CMake 
and the wxWidgets library. For this project, I utilized Visual Studio 2022 Community Edition as 
the compiler. However, please note that I have not tested it with MinGW and Linux, so there may 
be a need for some modifications if you plan to use those platforms.

In the current state of the project, there is no longer a requirement to pre-install wxWidgets. 
I have updated the CMake script to handle all the necessary tasks, including compiling the entire 
project. Additionally, I have included two CMD scripts that demonstrate how to compile and run the project. 
However, I will also provide you with a brief set of instructions in the next section.

### Compiling the project
To compile the project using Visual Studio 2022 Community Edition, simply enter the following command 
in your command line prompt:

```bash
mkdir build
cd build
cmake .. -G "Visual Studio 17 2022" 
cmake --build . --config Release
```  

After that, you will find the executable in the __Release__ folder within the build directory.
