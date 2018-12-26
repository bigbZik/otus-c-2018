cmake_minimum_required(VERSION 3.0)

if(NOT DEFINED ENV{TRAVIS_BUILD_NUMBER})
	set(ENV{TRAVIS_BUILD_NUMBER} 1)
endif()

project(otus-c-2018-tests-hw01 VERSION 1.0.$ENV{TRAVIS_BUILD_NUMBER} LANGUAGES C CXX)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_library(hw01_lib ../../../src/hw/hw01/hw01_lib.cpp)

add_executable(test_hw01 test_hw01.cpp)

set_target_properties(test_hw01 PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(test_hw01 ${Boost_LIBRARIES} hw01_lib)