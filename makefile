# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Source files
SRCS = main.cpp db.cpp

# Detect OS and set executable name accordingly
ifeq ($(OS),Windows_NT)
    TARGET = cpp_db.exe
else
    TARGET = cpp_db
endif

# Default target: build the executable
all: $(TARGET)

# Compile and link all sources into the executable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Clean build files
clean:
	rm -f $(TARGET) *.o

.PHONY: all clean

