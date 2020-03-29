cmake_minimum_required(VERSION 3.10.0)

project(leetcode CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

add_executable(
    unit_tests
    main.cc
    solutions/1135_connecting_cities_with_minimum_costs.cpp
    solutions/778_swim_in_rising_water.cc
    )

target_include_directories(unit_tests
                           PRIVATE /usr/local/include)

target_link_directories(unit_tests
                        PRIVATE /usr/local/lib)

target_link_libraries(
    unit_tests
    gtest
    pthread)

enable_testing()
add_test(
  NAME
    unit
  COMMAND
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
)

