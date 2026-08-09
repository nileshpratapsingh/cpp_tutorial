// utils.h

#define SUM(x) ((x) + (x))
#define PI 3.14159265359
#define RAND(x) (rand() % x)
#define RAND_RANGE(min, max) (rand() % ((max) - (min) + 1) + (min))

#pragma once

#include <boost/multiprecision/cpp_int.hpp> // IWYU pragma: export
#include <chrono>
#include <cmath>   // IWYU pragma: export
#include <cstddef> // IWYU pragma: export
#include <cstdint>
#include <cstdlib>  // IWYU pragma: export
#include <cstring>  // IWYU pragma: export
#include <ctime>    // IWYU pragma: export
#include <iostream> // IWYU pragma: export
#include <limits>   // IWYU pragma: export
#include <sstream>  // IWYU pragma: export
#include <string>
#include <thread>
#include <utility>   // IWYU pragma: export
#include <vector>    // IWYU pragma: export
#include <windows.h> // IWYU pragma: export

void print_array(int arr[], int size);
void initRandom();
int randomInt(int max);
int randomInt(int min, int max);
float randomFloat(float max);
float randomFloat(float min, float max);
