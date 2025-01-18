cmake_minimum_required(VERSION 3.10)
project(Solver)

# Set the C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(solver src/main.cpp src/report.cpp)

# Include directories for headers
include_directories(include)

# Add Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add the test executable
add_executable(solver_test test/report_test.cpp src/report.cpp)

# Link Google Test libraries to the test executable
target_link_libraries(solver_test GTest::GTest GTest::Main pthread)

# Enable debug
set(CMAKE_BUILD_TYPE Debug)
