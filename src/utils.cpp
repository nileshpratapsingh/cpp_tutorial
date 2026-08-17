// utils.cpp
#include "utils.h"

void utils::print_array(u64 arr[], u64 size, bool array_format) {
    if (array_format) {
        std::cout << "[ ";
        for (u64 i = 0; i < size - 1; i++) {
            std::cout << "'" << arr[i] << "', ";
        }
        std::cout << "'" << arr[size - 1] << "'" << " ]" << "\n" << std::endl;
    }

    for (u64 i = 0; i < size; i++) {
        std::cout << "Element " << i + 1 << ": " << arr[i] << std::endl;
    }
}

void utils::initRandom() {
#ifdef _WIN32
    srand(static_cast<u64>(time(nullptr)) + GetCurrentProcessId());
#else
    srand(static_cast<u64>(time(nullptr)));
#endif
}

u64 utils::randomInt(u64 max) { return rand() % max; }

u64 utils::randomInt(u64 min, u64 max) {
    return rand() % (max - min + 1) + min;
}

f64 utils::randomFloat(f64 max) {
    f64 value = static_cast<f64>(rand()) / RAND_MAX * max;
    return std::round(value * 100.0f) / 100.0f;
}

f64 utils::randomFloat(f64 min, f64 max) {
    return min + static_cast<f64>(rand()) / RAND_MAX * (max - min);
}

std::string utils::random_id_gen(u64 size) {
    const std::string key_set =
        "abcmnopqrHIJKLMNstuvwxyzABCDEFG56789OPQRSTUVWXYZ01234defghijkl";

    std::string id;
    id.reserve(size);

    for (u64 i = 0; i < size; i++) {
        u64 rand = randomInt(key_set.length());
        id.push_back(key_set[rand]);
    }

    return id;
}
