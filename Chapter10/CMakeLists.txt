cmake_minimum_required(VERSION 3.25)
project(Chapter10)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

set(HEADERS src/DivisionByZeroError.h)
set(SOURCES )
set(TESTS test/ExceptionHandlingTests.cpp)
add_executable(Chapter10Test ${HEADERS} ${SOURCES} ${TESTS})
target_link_libraries(Chapter10Test GTest::gtest_main GTest::gmock)
gtest_discover_tests(Chapter10Test)
