#include "utils.h"

class Base {
  /*
  Protected member of the class can be inherited by the derived class in prote
  and public visibility mode, But can't be accessed by the object that are
  created by the derived class
*/
protected:
  size_t a;

public:
  size_t b = 10;
};
/*
    In protected derivation the public member becomes protected
    which means they can't be accessed by the derived class object
 */
class Derived : protected Base {
    public:
        size_t b = 134;
};

int main() {
  Derived d1;
  std::cout << d1.b << std::endl;
  return EXIT_SUCCESS;
}
