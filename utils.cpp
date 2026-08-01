// utils.cpp
#include "utils.h"

void print_array(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    std::cout << "Element " << i + 1 << ": " << arr[i] << std::endl;
  }
}

void initRandom() {
#ifdef _WIN32
  srand(static_cast<unsigned int>(time(nullptr)) + GetCurrentProcessId());
#else
  srand(static_cast<unsigned int>(time(nullptr)));
#endif
}

int randomInt(int max) {
  return rand() % max;
}

int randomInt(int min, int max) {
  return rand() % (max - min + 1) + min;
}
