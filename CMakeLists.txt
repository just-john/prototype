cmake_minimum_required(VERSION 3.9)

project(untitled VERSION 1.0.0 DESCRIPTION "your bright idea goes here")


set (Boost_NO_SYSTEM_PATHS       ON)
set (Boost_USE_MULTITHREADED     ON)
set (Boost_USE_STATIC_RUNTIME    OFF)

find_package (Boost REQUIRED system filesystem)
find_package (OpenSSL REQUIRED)

link_directories (
    ${Boost_LIBRARY_DIRS}
    ${OPENSSL_LIBRARIES})

include_directories (
    ${Boost_INCLUDE_DIRS}
    ${OPENSSL_INCLUDE_DIRS}
    $ENV{PROJECT_SRC_DIR})

add_definitions(-DBOOST_LOG_DYN_LINK)

message(STATUS "OpenSSL version ${OPENSSL_VERSION}")


# compiler flags
set (CMAKE_CXX_FLAGS                "-Wall -ggdb -std=c++17")

# set (GCC_COVERAGE_COMPILE_FLAGS   "-fprofile-arcs -ftest-coverage")
# set (GCC_COVERAGE_LINK_FLAGS      "-lgcov")

# Target
add_subdirectory(src)
