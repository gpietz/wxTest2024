# wxTest2024
*** 


This is a small test project to learn how to create a C++ project using CMake and the wxWidgets library. 
I've worked on smaller C++ projects in the past, using CMake and wxWidgets, but I wanted to see how the 
toolchain has evolved over the years.
For this small project I used Visual Studio 2022 Community Edition as the compiler, 
but it should also work with MinGW and on Linux.

### Installing wxWidgets
To compile this project, wxWidgets must be installed and compiled. You can get the sources from
[wxwidgets homepage](https://www.wxwidgets.org/). Refer to the manuals for instructions on how to 
compile and create the required libraries.

For this project you'll need static libraries. To compile wxWidgets version 3.2.4 using 
Visual Studio 2022 Community Edition, open the file wx_vc17.sln located in the build/msw directory of the 
wxWidgets 3.2.4 source folder. From there, you can select either a release or debug build. If you are using 
a different compiler, refer to the wxWidgets documentation for the appropriate steps.

After the compilation is complete you need to set a a system environment variable named __WXWIDGETS_HOME__
that points to the wxWidgets installation root folder.

The remaining setup is handled by this project's CMake build script.
 
### Compiling the project
To compile the project with Visual Studio 2022 Community Edition, you just need to enter the following
command into your command line prompt:

```bash
mkdir build
cd build
cmake .. -G "Visual Studio 17 2022" 
cmake --build . --config Release
```  

After that you'll find the executable in the __Release__-folder of the build-directory,


*Note: The above instructions are tailored for Visual Studio 2022 Community Edition on Windows. 
If you are using MinGW or a Linux environment, the steps for compiling wxWidgets and the project may differ. 
Please consult the wxWidgets documentation specific to your compiler and operating system for accurate guidance.*
