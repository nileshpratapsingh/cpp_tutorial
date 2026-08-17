#include "utils.h"

class Employee {

private:
  int a, b, c;

public:
  int d, e, f;
  void setData(int a1, int b2, int c3);
  void getData() {
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << "e: " << e << std::endl;
    std::cout << "f: " << f << std::endl;
  }
};

void Employee::setData(int a1, int b2, int c3) {
  a = a1;
  b = b2;
  c = c3;
}

int main() {

  Employee Nilesh;

  Nilesh.d = 45;
  Nilesh.e = 81;
  Nilesh.f = 60;

  Nilesh.setData(23, 45, 64);
  Nilesh.getData();

  return EXIT_SUCCESS;
}
