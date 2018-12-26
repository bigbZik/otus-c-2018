cmake_minimum_required(VERSION 3.0)

if(NOT DEFINED ENV{TRAVIS_BUILD_NUMBER})
	set(ENV{TRAVIS_BUILD_NUMBER} 1)
endif()

project(otus-c-2018-hw01 VERSION 1.0.$ENV{TRAVIS_BUILD_NUMBER} LANGUAGES C CXX)


find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(config.h.in config.h)

add_library(hw01_lib hw01_lib.cpp)

add_executable(hw01 hw01.cpp)

add_executable(test_hw01 ../../../tests/hw/hw01/test_hw01.cpp)

target_link_libraries(hw01 hw01_lib)

target_link_libraries(test_hw01 ${Boost_LIBRARIES} hw01_lib)

set_target_properties(test_hw01 PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT bigbzik@gmail.com)

include(CPack)

enable_testing()
add_test(test_hw01 test_hw01)
