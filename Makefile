CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
LDFLAGS = -mconsole

BUILD_DIR := build

# All .cpp files
SRCS := $(wildcard *.cpp)

# Shared source files (not executables)
COMMON_SRCS := utils.cpp

# Programs (exclude shared sources)
PROGRAM_SRCS := $(filter-out $(COMMON_SRCS),$(SRCS))
BINS := $(PROGRAM_SRCS:%.cpp=$(BUILD_DIR)/%.exe)

all: $(BINS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.exe: %.cpp $(COMMON_SRCS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $< $(COMMON_SRCS) -o $@ $(LDFLAGS)

clean:
	rm -f $(BUILD_DIR)/*.exe
