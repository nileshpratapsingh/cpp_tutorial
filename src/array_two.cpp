#include "utils.h"

void swap(int &x, int &y) // Pass by reference
{
  int temp = x;
  x = y;
  y = temp;
}

int main() {
  int a = 5, b = 7;
  swap(a, b);
  std::cout << "The swap of a and b is: " << a << " " << b << std::endl;
  return 0;
}
