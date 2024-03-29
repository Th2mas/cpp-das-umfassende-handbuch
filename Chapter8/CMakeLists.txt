cmake_minimum_required(VERSION 3.19)
project(chapter8)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)
FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG master
)
FetchContent_MakeAvailable(fmt)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

set(HEADERS include/Sales.h include/Dynamic.h include/Comparison.h)
set(SOURCES src/Sales.cpp src/Dynamic.cpp src/Comparison.cpp)
set(TESTS test/SalesTest.cpp test/DynamicTest.cpp test/ComparisonTest.cpp)
add_executable(Chapter8Test ${HEADERS} ${SOURCES} ${TESTS})
target_link_libraries(Chapter8Test GTest::gtest_main GTest::gmock fmt::fmt)
gtest_discover_tests(Chapter8Test)
