#include "utils.h"

class Number {
  int a;

public:
  Number() : a(100) {}
  Number(int num) { a = num; }
  Number(Number &obj) {
    std::cout << "Copy Constructor" << std::endl;
    a = obj.a;
  }
  inline void display(void);
};

void Number::display(void) { std::cout << "The number is :" << a << std::endl; }

int main() {
  initRandom();
  int a = randomInt(100);
  Number n1(a);
  n1.display();
  Number n2(n1);
  return EXIT_SUCCESS;
}
