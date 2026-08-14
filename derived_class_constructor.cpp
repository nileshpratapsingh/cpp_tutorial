#include "utils.h"

class Base1 {
public:
  Base1() {}
  Base1(u64 a) { std::cout << "Base1 Constructor Called." << a << std::endl; }
};

class Base2 {
public:
  Base2(void) {}
  Base2(u64 a) { std::cout << "Base2 Constructor Called." << a << std::endl; }
};

class Derived1 : public Base1 {
  u64 Derived1_member;

public:
  Derived1(u64 a, u64 b) : Base1(b) {
    Derived1_member = a;
    std::cout << "Derived1 Constructor Called." << std::endl;
    std::cout << Derived1_member << std::endl;
  }
};

class Derived2 : public Base1, public Base2 {
  u64 Derived2_member;

public:
  Derived2(u64 a, u64 b, u64 c) : Base1(b), Base2(c), Derived2_member(a) {
    std::cout << "Derived1 Constructor Called." << std::endl;
    std::cout << Derived2_member << std::endl;
  }
};

int main() {
    utils::initRandom();
  u64 a, b, c;
  a = utils::randomInt(100);
  b = utils::randomInt(100);
  c = utils::randomInt(100);
  Derived1 d1(a, b);
  Derived2 d2(a, b, c);
  return EXIT_SUCCESS;
}
