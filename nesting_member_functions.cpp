#include "utils.h"
#include <cstddef>

class binary {
private:
  std::string s;
  void chk_bin();

public:
  void read();
  void ones_compliment();
  void display();
};

void binary::read(void) {
  std::cout << "Enter a binary number: ";
  std::cin >> s;
}

void binary::chk_bin(void) {
  for (size_t i = 0; i < s.length(); i++) {
    if (s.at(i) != '0' && s.at(i) != '1') {
      std::cout << "Incorrect Number." << std::endl;
      exit(0);
    }
  }
}

void binary::ones_compliment(void) {
  chk_bin();
  for (size_t i = 0; i < s.length(); i++) {
    if (s.at(i) == '0')
      s.at(i) = '1';
    else
      s.at(i) = '0';
  }
}

void binary::display() {
  std::cout << "Displaying Binary Number:" << std::endl;
  for (size_t i = 0; i < s.length(); i++) {
    std::cout << s.at(i);
  }
}

int main(int argc, char *argv[]) {
  binary b;
  b.read();
  b.display();
  b.ones_compliment();
  std::cout << "\n";
  b.display();
  return EXIT_SUCCESS;
}
