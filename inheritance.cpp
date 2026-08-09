#include "utils.h"

class Employees {
  void sayHello(void);

public:
  size_t id, salary;
  Employees() {}
  Employees(int EmpId) {
    id = EmpId;
    salary = 40;
  }
  void callHello(void);
};

void Employees::sayHello() { std::cout << "Hello Every One." << std::endl; }

/*
 * Note:
 * 1. Default Visibilty mode is Private
 * 2. Public Visibilty mode means public members of the base class become public
 * members of the derived class.
 * 3. Private Visibilty mode means public members of the base class becomes
 * private members for the derived class.
 * 4. The object of the derived class cannot acces the members of the base class
 * directly but it can be called inside the derived class.
 * 5. Private members are never inherited.
 *
 *  class <DERIVED CLASS NAME> : <VISIBILITY MODE> <BASE CLASS NAME>{};
 */

class Programmer : public Employees {
public:
  Programmer() {}
  Programmer(int EmpId) { id = EmpId; }
  size_t languaugeCode = 9;
  void getData(void);
  void callSayHello(void);
};

void Programmer::getData(void) { std::cout << id << std::endl; }

void Employees::callHello(void) { sayHello(); }

void Programmer::callSayHello(void) { callHello(); }

int main() {
  Employees Nilesh(54), Rohan(43);
  std::cout << Nilesh.salary << std::endl;
  std::cout << Rohan.salary << std::endl;
  Programmer Mohan(46);
  std::cout << Mohan.languaugeCode << std::endl;
  Mohan.getData();
  Mohan.callHello();
  return EXIT_SUCCESS;
}
