#include "utils.h"

class Number {
  u64 a;

public:
  Number() : a(utils::randomInt(100)) {}
  Number(u64 num) { a = num; }
  Number(Number &obj) {
    std::cout << "Copy Constructor" << std::endl;
    a = obj.a;
  }
  inline void display(void);
};

void Number::display(void) { std::cout << "The number is :" << a << std::endl; }

int main() {
  utils::initRandom();
  u64 a = utils::randomInt(100);
  Number n1(a);
  n1.display();
  Number n2(n1);
  return EXIT_SUCCESS;
}
