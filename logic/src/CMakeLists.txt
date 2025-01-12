# Add the Rendering subdirectory
add_subdirectory(Rendering)

# Add the main executable
add_executable(SDL2_Project main.cpp)

# Link the Rendering library to the main executable
target_link_libraries(SDL2_Project PRIVATE Rendering)
