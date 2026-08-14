#include "utils.h"

class Employee {
public:
 /*
  * Static Data Member does not change the value When the class object is created like other data members.
  */
  static int count; // default value is zero 0
  size_t id[100];

  void setData();
  void getData();
  /*
   * Static method can only access only other static method and static data member.
   * They can only access by the class name,
   */
  static void getCount();
};
// they can be accessed like this
int Employee::count = 0;

void Employee::setData() {
  if (count >= 100) {
    std::cout << "Employee list is full.\n";
    return;
  }

  std::cout << "Enter Employee ID: ";
  std::cin >> id[count];
  count++;
}

void Employee::getData() {
  for (int i = 0; i < count; i++) {
    std::cout << "Employee " << i + 1 << " ID: " << id[i] << '\n';
  }
}

void Employee::getCount() { std::cout << "Total Employees: " << count << '\n'; }

int main() {
  Employee *a = new Employee;

  size_t n;
  std::cout << "How many employees? ";
  std::cin >> n;

  for (size_t i = 0; i < n; i++) {
    a->setData();
  }

  a->getData();
  // no need to create the object
  // Can access them directly by there class name
  Employee::getCount();
  delete a;
  return EXIT_SUCCESS;
}
