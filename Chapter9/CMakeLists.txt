cmake_minimum_required(VERSION 3.19)
project(chapter9)

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

set(HEADERS include/Hero.h include/Superhero.h include/PictureFormat.h include/JpegPictureFormat.h include/Cloud.h include/Vehicle.h include/Bicycle.h include/MotorVehicle.h include/Motorcycle.h)
set(SOURCES src/Hero.cpp src/Superhero.cpp src/Vehicle.cpp src/Bicycle.cpp src/MotorVehicle.cpp src/Motorcycle.cpp)
set(TESTS test/SuperheroTests.cpp test/HeroTests.cpp test/PictureFormatTests.cpp test/MotorcycleTest.cpp)
add_executable(Chapter9Test ${HEADERS} ${SOURCES} ${TESTS})
target_link_libraries(Chapter9Test GTest::gtest_main GTest::gmock)
gtest_discover_tests(Chapter9Test)
