cmake_minimum_required(VERSION 3.5.0)

project(leetcode CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

add_subdirectory(googletest)
add_library(GMock::GMock ALIAS gmock)
add_library(GMock::Main ALIAS gmock_main)

add_library(GTest::GTest ALIAS gtest)
add_library(GTest::MAIN ALIAS gtest_main)

add_executable(
    unit_tests
    solutions/50_pow.cpp
    )

target_link_libraries(
    unit_tests
    gtest
    gtest_main
    pthread)

enable_testing()
add_test(
  NAME
    unit
  COMMAND
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
)

