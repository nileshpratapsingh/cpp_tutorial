#include <iostream>
#include <cstdlib>
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;

cpp_int factorial(size_t n) {
    cpp_int result = 1;

    for (size_t i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}

int main(int argc, char* argv[]){

    if(argc != 2){
        std::cout << "Usage: " << argv[0] << " <num1>\n";
        return EXIT_FAILURE;
    }

    size_t num1 = std::atoi(argv[1]);

    std::cout<<factorial(num1)<<std::endl;

    return EXIT_SUCCESS;
}
