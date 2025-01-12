# Create a library for the Rendering module
add_library(Rendering Rendering.cpp)

# Add the include directory for this library
target_include_directories(Rendering PUBLIC ${CMAKE_SOURCE_DIR}/include)
