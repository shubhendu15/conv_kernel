# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -fPIC -std=c++17 -Iinclude

# Source and Output
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
LIB_DIR = lib

# Target executable
TARGET = $(LIB_DIR)/lib_conv_kernel.so

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Create necessary directories if they don't exist
$(shell mkdir -p $(OBJ_DIR) $(LIB_DIR))

# Default rule
all: $(TARGET)

# Build shared directory
$(TARGET): $(OBJS)
	$(CXX) -shared -o $@ $^

# Compilation
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp 
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -rf $(OBJ_DIR) $(LIB_DIR)

# Phony targets
.PHONY: all clean

