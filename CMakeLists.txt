# main CMakeLists.txt file for the Imprint project
cmake_minimum_required(VERSION 3.5)
project(Imprint)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_subdirectory(core)
add_subdirectory(utils)
add_subdirectory(tests)
add_subdirectory(external/SQLiteCpp)