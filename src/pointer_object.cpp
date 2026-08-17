#include "utils.h"

class Complex {
  u64 real, imaginary, a;

public:
  Complex(u64 a)
      : real(utils::randomInt(100)), imaginary(utils::randomInt(100)), a(utils::randomInt(a)) {}
  void getData(void) const {
    std::cout << "The value of the real part is: " << real << std::endl;
    std::cout << "The value of the imaginary part is: " << imaginary
              << std::endl;
  }
};

int main() {
  utils::initRandom();
  Complex c(10);
  Complex *ptr = new Complex(100);
  ptr->getData();
  delete ptr;
  return EXIT_SUCCESS;
}
