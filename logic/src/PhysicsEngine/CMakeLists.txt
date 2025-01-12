# Add the Animation library
add_library(Animation STATIC Animation.cpp AnimationManager.cpp)

# Include the public headers
target_include_directories(Animation PUBLIC ${PROJECT_SOURCE_DIR}/include/Animation)

# Link SDL2 (if needed)
target_link_libraries(Animation PRIVATE SDL2::SDL2)
