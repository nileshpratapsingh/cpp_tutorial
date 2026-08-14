#include "utils.h"

// Executed in cpu registers for fast computation.
// Note: only declare them for the small computation.
inline size_t product(size_t a, size_t b) {
    return a * b;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " <num1> <num2>\n";
        return EXIT_FAILURE;
    }

    size_t num1 = std::atoi(argv[1]);
    size_t num2 = std::atoi(argv[2]);

    std::cout << "Product: " << product(num1, num2) << std::endl;
    std::cout << "argc: " << argc << std::endl;

    return EXIT_SUCCESS;
}
