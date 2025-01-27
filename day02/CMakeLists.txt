cmake_minimum_required(VERSION 3.22)
project(Solver)

# Enable testing
enable_testing()

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

# End-to-end test source files
set(END_TO_END_TEST_SOURCES
    test/end-to-end/solver_test.cpp
)

# Include directories for headers
include_directories(include)

# Add the main executable
add_executable(solver src/main.cpp ${SHARED_SOURCES})

# Add Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add the unit test executable
add_executable(unit_tests ${UNIT_TEST_SOURCES} ${SHARED_SOURCES})

# Link Google Test libraries to the unit test executable
target_link_libraries(unit_tests GTest::GTest GTest::Main pthread gmock gmock_main)

# Register the unit test executable with CTest
add_test(NAME unit_tests COMMAND unit_tests)

# Add the integration test executable
add_executable(integration_tests ${INTEGRATION_TEST_SOURCES} ${SHARED_SOURCES})

# Link Google Test libraries to the integration test executable
target_link_libraries(integration_tests GTest::GTest GTest::Main pthread)

# Register the integration test executable with CTest
add_test(NAME integration_tests COMMAND integration_tests)

# Add the end-to-end test executable
add_executable(end_to_end_tests ${END_TO_END_TEST_SOURCES} ${SHARED_SOURCES})

# Link Google Test libraries to the end-to-end test executable
target_link_libraries(end_to_end_tests GTest::GTest GTest::Main pthread)

# Register the end-to-end test executable with CTest
add_test(NAME end_to_end_tests COMMAND end_to_end_tests)

# Enable coverage
set(CMAKE_BUILD_TYPE Coverage)

# Set Make flags for code coverage
if(CMAKE_BUILD_TYPE STREQUAL "Coverage")
    message(STATUS "Building with coverage instrumentation")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -O0 -g")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage -O0 -g")
    set(COVERAGE_LINK_FLAGS "--coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${COVERAGE_LINK_FLAGS}")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ${COVERAGE_LINK_FLAGS}")
endif()
