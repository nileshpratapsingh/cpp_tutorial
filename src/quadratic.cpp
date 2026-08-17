#include "utils.h"

class Quadratic {
    private:
        s64 a, b, c;

    public:
        Quadratic(void) {}
        Quadratic(s64 a, s64 b, s64 c) {
            this->a = a;
            this->b = b;
            this->c = c;
        }

        s64 *find_discriminant() const {
            s64 D = (b * b) - (4 * a * c);
            return new s64{D};
        }

        uld *find_sqrt_discriminant() const {
            s64 *D = this->find_discriminant();

            if (*D < 0) {
                delete D;
                throw std::runtime_error("Roots are imaginary: discriminant < 0.");
            }

            uld sqrt_D = std::sqrtl(static_cast<uld>(*D));

            delete D;

            return new uld{sqrt_D};
        }

        uld *root_one() const {
            if (a == 0) {
                throw std::runtime_error("Root does not exist: 2a = 0.");
            }

            uld *sqrt_D = this->find_sqrt_discriminant();
            uld numr = -static_cast<uld>(b) + *sqrt_D;

            uld deno = 2.0L * static_cast<uld>(a);

            delete sqrt_D;
            return new uld{numr / deno};
        }

        uld *root_two() const {
            if (a == 0) {
                throw std::runtime_error("Root does not exist: 2a = 0.");
            }

            uld *sqrt_D = this->find_sqrt_discriminant();
            uld numr = -static_cast<uld>(b) - *sqrt_D;

            uld deno = 2.0L * static_cast<uld>(a);

            delete sqrt_D;
            return new uld{numr / deno};
        }

        std::pair<uld, uld> *return_roots() const {
            uld *r1 = this->root_one();
            uld *r2 = this->root_two();

            std::pair<uld, uld> *result = new std::pair<uld, uld>{*r1, *r2};

            delete r1;
            delete r2;
            return result;
        }
};

int main(int argc, char **argv) {
    utils::initRandom();
    s64 a, b, c;
    if (argc < 4 || argc > 4) {
        a = utils::randomInt(100);
        b = utils::randomInt(100);
        c = utils::randomInt(100);
    } else {
        a = std::stoull(argv[1]);
        b = std::stoull(argv[2]);
        c = std::stoull(argv[3]);
    }
    std::cout << "a = " << a << '\n';
    std::cout << "b = " << b << '\n';
    std::cout << "c = " << c << '\n';

    try {
        Quadratic *q = new Quadratic(a, b, c);

        s64 *D = q->find_discriminant();
        std::cout << "Discriminant = " << *D << '\n';
        delete D;

        std::cout << "The Equation is " << a << "x² + " << b << "x + " << c
            << " = 0.\n"
            << std::endl;
        std::pair<uld, uld> *result = q->return_roots();
        std::cout << "The roots are real:\n";
        std::cout << "x1 = " << result->first << '\n';
        std::cout << "x2 = " << result->second << '\n';

        delete result;
        delete q;
    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << '\n';
    }

    return EXIT_SUCCESS;
}
