#include "utils.h"

class shop {
public:
  std::string itemId[100];
  size_t itemPrice[100];
  size_t counter;
  void initCounter(void) { counter = 0; }
  void setPrice(void);
  void getPrice(void);
};

void shop::setPrice() {
  std::cout << "Enter item id: ";
  std::cin >> itemId[counter];
  std::cout << "Enter item price:";
  std::cin >> itemPrice[counter];
  counter++;
}

void shop::getPrice() {
  for (size_t i = 0; i < counter; i++) {
    std::cout << "Price of your item is: " << itemPrice[i] << " and "
              << "your itemId id id: " << itemId[i] << std::endl;
  }
}

int main() {
  shop s;
  s.initCounter();

  int n;
  printf("hello\n");
  std::cout << "How many items? ";
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    s.setPrice();
  }

  s.getPrice();

  return EXIT_SUCCESS;
}
