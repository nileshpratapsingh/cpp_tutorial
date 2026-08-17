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

using s64 = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;
using f64 = double;
using uld = long double;
using d64i = std::vector<u64>;
using d64f = std::vector<f64>;

namespace utils {
void print_array(u64 arr[], u64 size, bool array_format = false);
void initRandom();
u64 randomInt(u64 max);
u64 randomInt(u64 min, u64 max);
f64 randomFloat(f64 max);
f64 randomFloat(f64 min, f64 max);
std::string random_id_gen(u64 size);
} // namespace utils
