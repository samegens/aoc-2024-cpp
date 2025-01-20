cmake_minimum_required(VERSION 3.10)
project(Solver)

# Set the C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Shared source files
set(SHARED_SOURCES
    src/report.cpp
    src/report_parser.cpp
    src/report_checker.cpp
    src/solver.cpp
)

# Unit test source files
set(UNIT_TEST_SOURCES
    test/unit/report_test.cpp
    test/unit/report_parser_test.cpp
    test/unit/report_checker_test.cpp
    test/unit/solver_test.cpp
)

# Integration test source files
set(INTEGRATION_TEST_SOURCES
    test/integration/solver_test.cpp
)

# Add the main executable
add_executable(solver src/main.cpp ${SHARED_SOURCES})

# Include directories for headers
include_directories(include)

# Add Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add the unit test executable
add_executable(unit_tests ${UNIT_TEST_SOURCES} ${SHARED_SOURCES})

# Link Google Test libraries to the unit test executable
target_link_libraries(unit_tests GTest::GTest GTest::Main pthread gmock gmock_main)

# Add the integration test executable
add_executable(integration_tests ${INTEGRATION_TEST_SOURCES} ${SHARED_SOURCES})

# Link Google Test libraries to the integration test executable
target_link_libraries(integration_tests GTest::GTest GTest::Main pthread)

# Enable debug
set(CMAKE_BUILD_TYPE Debug)
