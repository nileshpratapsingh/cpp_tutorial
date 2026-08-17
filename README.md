# C++ Project Build System

This project uses a simple **Makefile** to compile every `.cpp` file in the project directory into a separate executable.

## Requirements

- g++
- GNU Make
- C++17 compatible compiler

### Windows (MSYS2)

Install:

- GCC (g++)
- make

Example:

```sh
pacman -S mingw-w64-ucrt-x86_64-gcc
pacman -S make
```

---

## Project Structure

```
.
├── Makefile
├── src/
└── build/
```

`utils.cpp` is treated as a shared source file and is linked with every executable.

---

## Build

Compile every program:

```sh
make
```

Output:

```
build/
├── program1.exe
├── program2.exe
└── program3.exe
```

---

## Run

Example:

```sh
./build/program1.exe
```

or in PowerShell:

```powershell
.\build\program1.exe
```

---

## Clean

Remove all generated executables.

```sh
make clean
```

---

## How it Works

### Compiler

```make
CXX = g++
```

Uses the GNU C++ compiler.

---

### Compiler Flags

```make
CXXFLAGS = -Wall -Wextra -std=c++17
```

| Flag | Description |
|------|-------------|
| `-Wall` | Enable common warnings |
| `-Wextra` | Enable additional warnings |
| `-std=c++17` | Compile using the C++17 standard |

---

### Linker Flags

```make
LDFLAGS = -mconsole
```

Creates a console application on Windows.

---

### Build Directory

```make
BUILD_DIR := build
```

All executables are placed inside the `build` folder.

---

### Source Files

```make
SRCS := $(wildcard *.cpp)
```

Automatically finds every `.cpp` file in the src(source) directory.

Example:

```
main.cpp
array.cpp
friend.cpp
utils.cpp
```

---

### Shared Source Files

```make
COMMON_SRCS := utils.cpp
```

These files are compiled and linked into every executable but are **not** built as standalone programs.

---

### Executable Sources

```make
PROGRAM_SRCS := $(filter-out $(COMMON_SRCS),$(SRCS))
```

Removes `utils.cpp` from the executable list.

Example:

```
main.cpp
array.cpp
friend.cpp
```

---

### Executables

```make
BINS := $(PROGRAM_SRCS:%.cpp=$(BUILD_DIR)/%.exe)
```

Produces:

```
build/main.exe
build/array.exe
build/friend.exe
```

---

### Build Rule

```make
$(BUILD_DIR)/%.exe: %.cpp $(COMMON_SRCS)
```

Each executable is built by compiling:

- the source file
- `utils.cpp`

Example:

```sh
g++ main.cpp utils.cpp -o build/main.exe
```

---

## Adding a New Program

Simply create another `.cpp` file.

Example:

```
stack.cpp
```

Then run:

```sh
make
```

The Makefile automatically builds:

```
build/stack.exe
```

No changes to the Makefile are required.

---

## Notes

- Every `.cpp` file except `utils.cpp` becomes an executable.
- `utils.cpp` is automatically linked with each program.
- Supports C++17.
- New source files are detected automatically.
