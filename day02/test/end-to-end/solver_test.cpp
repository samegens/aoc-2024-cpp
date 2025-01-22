#include <gtest/gtest.h>
#include <fstream>
#include <cstdlib> // For std::system
#include <sstream>
#include <string>
#include <cstdio> // For std::remove

class EndToEndTest : public ::testing::Test {
protected:
    std::string inputFilename = "input.txt";
    std::string outputFilename = "output.txt";

    // Runs before each test
    void SetUp() override {
        // Ensure no leftover files exist
        CleanupFiles();
    }

    // Runs after each test
    void TearDown() override {
        // Cleanup temporary files
        CleanupFiles();
    }

    void WriteTemporaryFile(const std::string &filename, const std::string &content) {
        std::ofstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Could not create file: " + filename);
        }
        file << content;
        file.close();
    }

    std::string ReadFile(const std::string &filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Could not read file: " + filename);
        }
        return std::string((std::istreambuf_iterator<char>(file)),
                           std::istreambuf_iterator<char>());
    }

    void CleanupFiles() {
        std::remove(inputFilename.c_str());
        std::remove(outputFilename.c_str());
    }
};

TEST_F(EndToEndTest, FullSolverWorkflowUsingExe) {
    // Arrange
    std::string inputData = R"(7 6 4 2 1
1 2 7 8 9
9 7 6 2 1
1 3 2 4 5
8 6 4 4 1
1 3 6 7 9)";
    WriteTemporaryFile(inputFilename, inputData);

    // Act
    std::string command = "./solver > " + outputFilename;
    int exitCode = std::system(command.c_str());

    // Assert
    ASSERT_EQ(exitCode, 0) << "Solver did not execute successfully.";

    std::string actualOutput = ReadFile(outputFilename);
    std::string expectedOutput =
        "Part 1: 2\n"
        "Part 2: 4\n";
    EXPECT_EQ(actualOutput, expectedOutput);
}
