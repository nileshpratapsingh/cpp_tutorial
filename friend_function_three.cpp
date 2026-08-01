#include "utils.h"

class Y;
class X {
  size_t x;

public:
  void setData(size_t a);
  void display(void);
  friend size_t add(X, Y);
};
class Y {
  size_t y;

public:
  void setData(size_t a);
  void display(void);
  friend size_t add(X, Y);
};
void X::setData(size_t a) { x = a; }
void Y::setData(size_t a) { y = a; }
void X::display(void) { std::cout << "The Number is : " << x << std::endl; }
void Y::display(void) { std::cout << "The Number is : " << y << std::endl; }
size_t add(X x1, Y y1) { return (x1.x + y1.y); }
int main() {
  X a;
  Y b;
  size_t n1, n2;
  initRandom();
  n1 = randomInt(100);
  n2 = randomInt(100);
  a.setData(n1);
  b.setData(n2);
  a.display();
  b.display();
  size_t res = add(a, b);
  std::cout << "The Sum is : " << res << std::endl;
  return EXIT_SUCCESS;
}
