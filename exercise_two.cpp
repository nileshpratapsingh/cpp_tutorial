#include "utils.h"

using u64 = std::uint64_t;
using u32 = std::uint32_t;
using ll  = long long;
using ld  = long double;
using f64 = double;

using d64 = std::vector<u64>;

class calculator {
protected:
    u64 result = 0;

public:
    u64 get_data() const;
    void set_data(u64 a);

    void add(u64 a, u64 b);
    void subtract(u64 a, u64 b);
    void multiply(u64 a, u64 b);
    bool divide(u64 a, u64 b);
};

void calculator::set_data(u64 a) {
    result = a;
}

u64 calculator::get_data() const {
    return result;
}

void calculator::add(u64 a, u64 b) {
    result = a + b;
}

void calculator::subtract(u64 a, u64 b) {
    result = a - b;
}

void calculator::multiply(u64 a, u64 b) {
    result = a * b;
}

bool calculator::divide(u64 a, u64 b) {
    if (b == 0) {
        std::cerr << "Error: division by zero\n";
        return false;
    }
    result = a / b;
    return true;
}
class scientific_calculator : public calculator {
public:

    f64 sine(f64 a);
    f64 cosine(f64 a);
    f64 tangent(f64 a);

    f64 cotangent(f64 a);
    f64 secant(f64 a);
    f64 cosecant(f64 a);

    f64 logarithm(f64 a);
    f64 natural_log(f64 a);

    f64 exponential(f64 a);
    f64 square_root(f64 a);

    f64 power(f64 a, f64 b);
};

f64 scientific_calculator::sine(f64 a) {
    return std::sin(a);
}

f64 scientific_calculator::cosine(f64 a) {
    return std::cos(a);
}

f64 scientific_calculator::tangent(f64 a) {
    return std::tan(a);
}

f64 scientific_calculator::cotangent(f64 a) {
    f64 value = std::tan(a);
    if (value == 0) {
        std::cerr << "Error: cotangent undefined\n";
        return 0;
    }
    return 1.0 / value;
}

f64 scientific_calculator::secant(f64 a) {
    f64 value = std::cos(a);
    if (value == 0) {
        std::cerr << "Error: secant undefined\n";
        return 0;
    }
    return 1.0 / value;
}

f64 scientific_calculator::cosecant(f64 a) {
    f64 value = std::sin(a);
    if (value == 0) {
        std::cerr << "Error: cosecant undefined\n";
        return 0;
    }
    return 1.0 / value;
}
f64 scientific_calculator::logarithm(f64 a) {
    if (a <= 0) {
        std::cerr << "Error: log requires a positive number\n";
        return 0;
    }
    return std::log10(a);
}

f64 scientific_calculator::natural_log(f64 a) {
    if (a <= 0) {
        std::cerr << "Error: ln requires a positive number\n";
        return 0;
    }
    return std::log(a);
}

f64 scientific_calculator::exponential(f64 a) {
    return std::exp(a);
}

f64 scientific_calculator::square_root(f64 a) {
    if (a < 0) {
        std::cerr << "Error: square root of negative number\n";
        return 0;
    }
    return std::sqrt(a);
}

f64 scientific_calculator::power(f64 a, f64 b) {
    return std::pow(a, b);
}
int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout
            << "Usage:\n"
            << "  build/exercise_two.exe add <a> <b> ...\n"
            << "  build/exercise_two.exe subtract <a> <b>\n"
            << "  build/exercise_two.exe multiply <a> <b>\n"
            << "  build/exercise_two.exe divide <a> <b>\n"
            << "  build/exercise_two.exe sin <a>\n"
            << "  build/exercise_two.exe cos <a>\n"
            << "  build/exercise_two.exe tan <a>\n"
            << "  build/exercise_two.exe cot <a>\n"
            << "  build/exercise_two.exe sec <a>\n"
            << "  build/exercise_two.exe csc <a>\n"
            << "  build/exercise_two.exe log <a>\n"
            << "  build/exercise_two.exe ln <a>\n"
            << "  build/exercise_two.exe sqrt <a>\n"
            << "  build/exercise_two.exe exp <a>\n"
            << "  build/exercise_two.exe pow <a> <b>\n";
        return EXIT_FAILURE;
    }

    std::string choice = argv[1];
    calculator calc;
    scientific_calculator sc;
    if (choice == "add") {
        u64 result = 0;
        for (int i = 2; i < argc; ++i) {
            u64 value = std::stoull(argv[i]);
            calc.add(result, value);
            result = calc.get_data();
        }
        std::cout << "Result: " << result << '\n';
    }
    else if (choice == "subtract") {
        if (argc != 4) {
            std::cerr << "Usage: calculator subtract <a> <b>\n";
            return EXIT_FAILURE;
        }
        u64 a = std::stoull(argv[2]);
        u64 b = std::stoull(argv[3]);
        calc.subtract(a, b);
        std::cout << "Result: "
                  << calc.get_data()
                  << '\n';
    }
    else if (choice == "multiply") {
        if (argc != 4) {
            std::cerr << "Usage: calculator multiply <a> <b>\n";
            return EXIT_FAILURE;
        }
        u64 a = std::stoull(argv[2]);
        u64 b = std::stoull(argv[3]);
        calc.multiply(a, b);
        std::cout << "Result: "
                  << calc.get_data()
                  << '\n';
    }
    else if (choice == "divide") {
        if (argc != 4) {
            std::cerr << "Usage: calculator divide <a> <b>\n";
            return EXIT_FAILURE;
        }
        u64 a = std::stoull(argv[2]);
        u64 b = std::stoull(argv[3]);
        if (calc.divide(a, b)) {
            std::cout << "Result: "
                      << calc.get_data()
                      << '\n';
        }
    }
    else if (choice == "sin") {
        f64 a = std::stod(argv[2]);
        std::cout << "Result: "
                  << sc.sine(a)
                  << '\n';
    }
    else if (choice == "cos") {
        f64 a = std::stod(argv[2]);
        std::cout << "Result: "
                  << sc.cosine(a)
                  << '\n';
    }
    else if (choice == "tan") {
        f64 a = std::stod(argv[2]);
        std::cout << "Result: "
                  << sc.tangent(a)
                  << '\n';
    }
    else if (choice == "cot") {
        f64 a = std::stod(argv[2]);
        std::cout << "Result: "
                  << sc.cotangent(a)
                  << '\n';
    }
    else if (choice == "sec") {
        f64 a = std::stod(argv[2]);
        std::cout << "Result: "
                  << sc.secant(a)
                  << '\n';
    }
    else if (choice == "csc") {
        f64 a = std::stod(argv[2]);
        std::cout << "Result: "
                  << sc.cosecant(a)
                  << '\n';
    }
    else if (choice == "log") {
        f64 a = std::stod(argv[2]);
        std::cout << "Result: "
                  << sc.logarithm(a)
                  << '\n';
    }
    else if (choice == "ln") {
        f64 a = std::stod(argv[2]);
        std::cout << "Result: "
                  << sc.natural_log(a)
                  << '\n';
    }
    else if (choice == "sqrt") {
        f64 a = std::stod(argv[2]);
        std::cout << "Result: "
                  << sc.square_root(a)
                  << '\n';
    }
    else if (choice == "exp") {
        f64 a = std::stod(argv[2]);
        std::cout << "Result: "
                  << sc.exponential(a)
                  << '\n';
    }
    else if (choice == "pow") {
        if (argc != 4) {
            std::cerr << "Usage: calculator pow <base> <exponent>\n";
            return EXIT_FAILURE;
        }
        f64 a = std::stod(argv[2]);
        f64 b = std::stod(argv[3]);
        std::cout << "Result: "
                  << sc.power(a, b)
                  << '\n';
    }

    else {
        std::cerr << "Unknown operation: "
                  << choice
                  << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
