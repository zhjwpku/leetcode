cmake_minimum_required(VERSION 3.10.0)

project(leetcode CXX)

set(CMAKE_CXX_STANDARD 11)

if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

add_executable(
    unit_tests
    main.cc
    solutions/50_pow.cpp
    )

target_link_libraries(
    unit_tests
    gtest
    )

enable_testing()
add_test(
  NAME
    unit
  COMMAND
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
  )

