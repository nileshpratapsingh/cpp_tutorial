#include "utils.h"

class Complex {
  size_t a, b;

public:
  void setnumber(size_t n1, size_t n2);
  void printNumber();
  /*
   * requires permission from the class as a friend(keyword)
   */
  friend Complex sumComplex(Complex o1, Complex o2);
};

void Complex::setnumber(size_t n1, size_t n2) {
  a = n1;
  b = n2;
}

void Complex::printNumber() {
  std::cout << "Your Number is : " << a << " + i" << b << std::endl;
}

/*
 * no scope inside the class
 */
Complex sumComplex(Complex o1, Complex o2) {
  Complex o3;
  o3.setnumber((o1.a + o2.a), (o1.b + o2.b));
  return o3;
}

int main() {
  Complex c1, c2, sum;
  c1.setnumber(10, 20);
  c1.printNumber();
  c2.setnumber(30, 40);
  c2.printNumber();
  sum = sumComplex(c1, c2);
  sum.printNumber();
  return EXIT_SUCCESS;
}
