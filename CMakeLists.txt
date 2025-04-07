cmake_minimum_required(VERSION 3.14)
project(knife)

# Enable C++17 or later
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(gtest_force_shared_crt ON CACHE BOOL "Use shared CRT with GoogleTest" FORCE)

# Add your library
add_library(knife INTERFACE)
target_include_directories(knife INTERFACE ${CMAKE_SOURCE_DIR}/knife)

# Add GoogleTest from submodule
add_subdirectory(external/googletest)

enable_testing()

# Add test executables
file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS tests/*.cpp)
add_executable(knife_tests ${TEST_SOURCES})
target_link_libraries(knife_tests gtest_main knife)

include(GoogleTest)
gtest_discover_tests(knife_tests)