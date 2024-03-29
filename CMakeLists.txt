cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(wxTest2024_2 LANGUAGES CXX)

include(FetchContent)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(wxBUILD_SHARED OFF)

message(STATUS "Downloading wxWidgets from github...")

FetchContent_Declare(
        wxWidgets
        GIT_REPOSITORY https://github.com/wxWidgets/wxWidgets.git
        GIT_TAG v3.2.4 # Version of wxWidgets to be used
        GIT_SHALLOW ON
)

FetchContent_MakeAvailable(wxWidgets)

# Define project source files
set(SRCS src/main.cpp)

# Add project source files
add_executable(${CMAKE_PROJECT_NAME} WIN32 ${SRCS})

# Link against wxWidgets
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE wxcore wxnet)
