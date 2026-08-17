#include "utils.h"

class Base {
  size_t id1;

public:
  size_t id2;
  Base() {}
  Base(size_t a) { id1 = a; }
  void setData(void);
  size_t getData1();
  size_t getData2();
};

class Derived : public Base {
public:
  size_t id3;
  Derived() {}
  Derived(size_t a) { id3 = a; }
  void process(void);
  void display(void);
};

void Base::setData(void) {
  id1 = 468;
  id2 = 456;
}

size_t Base::getData1() { return id1; }

size_t Base::getData2() { return id2; }

void Derived::process() { id3 = id2 * getData1(); }

void Derived::display() {
  std::cout << "Value of data 1 is :" << getData1() << std::endl;
  std::cout << "Value of data 2 is :" << getData2() << std::endl;
  std::cout << "Value of data 3 is :" << id3 << std::endl;
}

int main() {
  Derived d1;
  d1.setData();
  d1.process();
  d1.display();
  return EXIT_SUCCESS;
}
