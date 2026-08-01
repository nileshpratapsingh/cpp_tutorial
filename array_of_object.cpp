#include "utils.h"
#include <cstdlib>
#include <iostream>

class Employee {
  size_t id;
  size_t salary;
  static size_t count;

public:
  void setId(void);
  void getId(void);
};

void Employee::setId() {
  std::cout << "Enter the ID: ";
  if (!(std::cin >> id)) {
    std::cout << "Id should be an integer." << std::endl;
    std::exit(EXIT_FAILURE);
  }
  count++;
}

void Employee::getId(void) { std::cout << "The Id is: " << id << std::endl; }

size_t Employee::count = 0;

int main() {
  Employee a[4];
  for (size_t i = 0; i < 4; i++) {
    a[i].setId();
  }
  for (size_t i = 0; i < 4; i++) {
    a[i].getId();
  }
  return EXIT_SUCCESS;
}
