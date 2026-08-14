#include "utils.h"

class Base1 {
public:
  void greet(void) { std::cout << "hello from Base1" << std::endl; }
};

class Base2 {
public:
  void greet(void) { std::cout << "Hello from Base2" << std::endl; }
};

class Derived : public Base1, public Base2 {
public:
  void greet_one(void) { Base1::greet(); }
  void greet_two(void) { Base2::greet(); }
  void greet_all(void) {
    Base1::greet();
    Base2::greet();
  }
};

int main() {
  Derived d1;
  d1.greet_one();
  d1.greet_two();
  d1.greet_all();
  return EXIT_SUCCESS;
}
