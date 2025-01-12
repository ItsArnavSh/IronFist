cmake_minimum_required(VERSION 3.15)
project(SDL2_Project LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add subdirectories for source code
add_subdirectory(src)
