# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -Wall -g `sdl2-config --cflags`
# Linker flags
LDFLAGS = `sdl2-config --libs`

# Target
TARGET = IronFist

# Sources
SOURCES = $(wildcard *.cpp)

# Build rule
$(TARGET): $(SOURCES)
	$(CXX) -o $(TARGET) $(SOURCES) $(CXXFLAGS) $(LDFLAGS)

# Clean rule
clean:
	rm -f $(TARGET)
