cmake_minimum_required(VERSION 3.10)
project(Solver)

# Set the C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(solver main.cpp)

# Enable debug
set(CMAKE_BUILD_TYPE Debug)
