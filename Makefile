CXX = clang++
CXXFLAGS = -Wall -Wextra -std=c++17
LDFLAGS = -mconsole

BUILD_DIR := build
ASM_DIR := asm

# All .cpp files
SRCS := $(wildcard src/ *.cpp)

# Shared source files (not executables)
COMMON_SRCS := utils.cpp

# Programs (exclude shared sources)
PROGRAM_SRCS := $(filter-out $(COMMON_SRCS),$(SRCS))
BINS := $(PROGRAM_SRCS:%.cpp=$(BUILD_DIR)/%.exe)

.PHONY: all asm clean

all: $(BUILD_DIR) $(BINS)

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Create assembly directory
$(ASM_DIR):
	if not exist "$(ASM_DIR)" mkdir "$(ASM_DIR)"

# Build executables
$(BUILD_DIR)/%.exe: %.cpp $(COMMON_SRCS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $< $(COMMON_SRCS) -o $@ $(LDFLAGS)

# Generate assembly
asm: $(ASM_DIR)
	@for src in $(SRCS); do \
		echo "Generating $$src -> $(ASM_DIR)/$${src%.cpp}.s"; \
		$(CXX) $(CXXFLAGS) -S -fverbose-asm -masm=intel $$src -o $(ASM_DIR)/$${src%.cpp}.s; \
	done

# Clean generated files
clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(ASM_DIR)
