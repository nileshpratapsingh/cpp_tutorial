CXX      = g++
CXXFLAGS = -Wall -Wextra -std=c++17
LDFLAGS  = -mconsole

BUILD_DIR := build
SRCS := $(wildcard *.cpp)
BINS := $(SRCS:%.cpp=$(BUILD_DIR)/%.exe)

all: $(BINS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.exe: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm -f $(BUILD_DIR)/*.exe
