#include "utils.h"

int main() {
  utils::initRandom();
  u64 *ptr = new u64(45);
  std::cout << "Address: " << ptr << std::endl; // Address: 0x255d6afb130
  std::cout << "Value: " << *ptr << std::endl;  // Value: 45
  delete ptr;

  u64 size = utils::randomInt(50);
  u64 *arr = new u64[size];
  for (u64 i = 0; i < size; i++) {
    arr[i] = utils::randomInt(100);
  }
  utils::print_array(arr, size, true);
  delete[] arr;
  return EXIT_SUCCESS;
}
