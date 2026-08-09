#include "utils.h"

int count = 0;
class num {
public:
  num() {
    count++;
    std::cout << "This is the time where constructor is called for the object "
                 "number :"
              << count << std::endl;
  }

  ~num() { std::cout << "destructor called " << count << std::endl; }
};

int main() {
  num n1;
  num n2;
  return EXIT_SUCCESS;
}
