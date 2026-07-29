#include "utils.h"

class Employee {
public:
  static int count;
  size_t id[100];

  void setData();
  void getData();
  static void getCount();
};

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
  Employee a;

  size_t n;
  std::cout << "How many employees? ";
  std::cin >> n;

  for (size_t i = 0; i < n; i++) {
    a.setData();
  }

  a.getData();
  Employee::getCount();

  return EXIT_SUCCESS;
}
