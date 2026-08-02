#include "utils.h"

class master {
  size_t a, b;

public:
  master(void);
  master(size_t x);
  master(size_t x, size_t y);
  void printNumber(void);
};
master::master(void) {
  a = 0;
  b = 0;
}
master::master(size_t x) {
  a = x;
  b = 0;
}
master::master(size_t x, size_t y) {
  a = x;
  b = y;
}
void master::printNumber(void) {
  std::cout << "The value of a and b is : " << a << " " << b << std::endl;
}

int main() {
  master m1, m2(11), m3(324, 765);
  m1.printNumber();
  m2.printNumber();
  m3.printNumber();
  return EXIT_SUCCESS;
}
