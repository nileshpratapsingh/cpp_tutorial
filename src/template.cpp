#include "utils.h"

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << add(3, 5) << std::endl;          // int
    std::cout << add(2.5, 4.1) << std::endl;      // double
    std::cout << add(1.2f, 3.4f) << std::endl;    // float

    return EXIT_SUCCESS;
}
