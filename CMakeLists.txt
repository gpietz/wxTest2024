cmake_minimum_required(VERSION 3.27)
project(wxTest2024_2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(wxWidgets_ROOT_DIR $ENV{WXWIDGETS_HOME})
set(wxWidgets_CONFIGURATION mswu)

# Find wxWidgets
find_package(wxWidgets REQUIRED core base)
include(${wxWidgets_USE_FILE})

# Add your source files
add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)

# Link against wxWidgets
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES})

# Check if the operating system is Windows
if(WIN32)
    set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
            WIN32_EXECUTABLE YES
    )
endif()
