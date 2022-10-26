project(tests VERSION 1.0)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_RELEASE} /MTd")

set(VCPKG_TARGET_TRIPLET "x86-windows-static")
set(VCPKG_BUILD_TYPE ${CMAKE_BUILD_TYPE})
include(C:/My/Projects/vcpkg/scripts/buildsystems/vcpkg.cmake)

find_package(GTest CONFIG REQUIRED)

add_executable(tests tests.cpp)

target_include_directories(tests PUBLIC "../include")
target_link_libraries(tests PRIVATE GTest::gtest GTest::gtest_main)

enable_testing(True)
add_test(NAME tests COMMAND tests)
