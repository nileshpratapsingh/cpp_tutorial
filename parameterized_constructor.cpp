#include "utils.h"

class comp {
  size_t a, b;

public:
  comp(size_t, size_t);
  void printNumber(void);
};
comp::comp(size_t x, size_t y) {
  a = x;
  b = y;
}
void comp::printNumber(void) {
  std::cout << "The Number is: " << a << std::endl;
  std::cout << "The Number is: " << b << std::endl;
}

int main() {
  comp a1(20, 30);
  a1.printNumber();
  return EXIT_SUCCESS;
}
