# wxTest2024
*** 


This is a small test project to find out how to create a C++ project with CMake and the library
wxWidgets. As compiler I used Visual Studio 2022 in the Community Edition, but it should also
work with MinGW and Linux.
 

### Installing wxWidgets
To compile this project you need to install and compile wxWidgets. You can get the sources from
[wxwidgets homepage](https://www.wxwidgets.org/). Check the manuals how to compile and create the 
required libraries.

For this project you'll need static libraries. I've compiled it using Visual Studio 2022 Community Edition.
To do this just open the file __wx_vc17.sln__ in the __build/msw__ directory and select release or debug build.
If you want to use another compiler check the wxWidgets documentation.

After compiling has finished you need to set a system environment variable that will point to the wxWidgets
installation with the name __WXWIDGETS_HOME__ and add the root folder or the wxWidgets installation to it. 

The rest ist done by the CMake build script of this project.  
 

### Compiling the project
To compile the project using the Visual Studio 2022 Community Edition you just need to enter the folliwng
command into your command line prompt:

```bash
mkdir build
cd build
cmake .. -G "Visual Studio 17 2022" 
cmake --build . --config Release
```  

After that you'll find the executable in the __Release__-folder of the build-directory,
