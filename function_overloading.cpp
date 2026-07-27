#include <iostream>
#include <cstring>
#include <cstdlib>

char* sum(const char* a, const char* b) {
    char* result = new char[std::strlen(a) + std::strlen(b) + 1];
    std::strcpy(result, a);
    std::strcat(result, b);
    return result;
}

size_t sum(size_t a, size_t b) {
    return a + b;
}

size_t volume(size_t r,size_t h){
    return 3.14 * r * r * h;
}

size_t volume(size_t l,size_t b,size_t h){
    return l * b * h;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <num1> <num2>" << std::endl;
        return EXIT_FAILURE;
    }

    char* joined = sum(argv[1], argv[2]);
    std::cout << "String: " << joined << std::endl;
    delete[] joined;

    size_t num1 = std::atoi(argv[1]);
    size_t num2 = std::atoi(argv[2]);
    size_t num3 = std::atoi(argv[3]);
    std::cout << "Sum: " << sum(num1, num2) << std::endl;
    std::cout << "Volume Cylender: " << volume(num1, num2)<< std::endl;
    std::cout << "Volume Cuboid: " << volume(num1, num2, num3) << std::endl;

    return EXIT_SUCCESS;
}
