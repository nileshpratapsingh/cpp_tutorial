#include "utils.h"

class Complex {
  size_t a;
  size_t b;

public:
  void setData(size_t v1, size_t v2);
  void setDataBySum(Complex o1, Complex o2);
  void printNumber();
};

void Complex::setData(size_t v1, size_t v2) {
  a = v1;
  b = v2;
}

void Complex::setDataBySum(Complex o1, Complex o2) {
  a = o1.a + o2.a;
  b = o1.b + o2.b;
}

void Complex::printNumber() {
  std::cout << "Your complex number is" << a << "+i" << b << std::endl;
}

int main(){

    Complex c, d ,e;
    c.setData(10, 30);
    c.printNumber();

    d.setData(20, 40);
    d.printNumber();

    e.setDataBySum(c,d);
    e.printNumber();

    return EXIT_SUCCESS;
}
