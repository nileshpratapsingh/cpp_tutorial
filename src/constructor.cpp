#include "utils.h"
class Complex {
  size_t a, b;

public:
  // Constructor is declared as same as the name of the class
  Complex();

  void printNumber(void);
};
Complex::Complex(
    void) { // this is a default constructor does not take any argument
  a = 10;
  b = 20;
}
void Complex::printNumber() { std::cout << a << ":" << b << std::endl; }

int main() {
  Complex *a1 = new Complex;
  a1->printNumber();
  delete a1;
  return EXIT_SUCCESS;
}
