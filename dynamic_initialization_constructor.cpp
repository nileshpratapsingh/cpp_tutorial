#include "utils.h"

class Bank_Deposite {
  double principle;
  double interest_rate;
  size_t years;
  double return_value;

public:
  Bank_Deposite();
  Bank_Deposite(size_t p, size_t y, size_t r);
  Bank_Deposite(size_t p, size_t y, float r);

  void display() const;
};

// Default constructor
Bank_Deposite::Bank_Deposite()
    : principle(0), interest_rate(0.0), years(0), return_value(0.0) {}

// Integer interest rate (e.g. 10%)
Bank_Deposite::Bank_Deposite(size_t p, size_t y, size_t r)
    : principle(p), interest_rate(r / 100.0), years(y), return_value(p) {
  for (size_t i = 0; i < years; i++) {
    return_value *= (1.0 + interest_rate);
  }
}

// Floating-point interest rate (e.g. 10.75%)
Bank_Deposite::Bank_Deposite(size_t p, size_t y, float r)
    : principle(p), interest_rate(r / 100.0), years(y), return_value(p) {
  for (size_t i = 0; i < years; i++) {
    return_value *= (1.0 + interest_rate);
  }
}

void Bank_Deposite::display() const {
  std::cout << "Principal Amount : " << principle << '\n';
  std::cout << "Interest Rate    : " << interest_rate * 100 << "%\n";
  std::cout << "Years            : " << years << '\n';
  std::cout << "Return Value     : " << return_value << "\n\n";
}

int main() {
  initRandom();

  while (true) {
    size_t principal = randomInt(1000) + 1;
    size_t years = randomInt(10) + 1;

    size_t intRate = randomInt(20) + 1;   // 1% - 20%
    float floatRate = randomFloat(20.0f); // 0.00% - 20.00%

    Bank_Deposite bd1(principal, years, intRate);
    Bank_Deposite bd2(principal, years, floatRate);
    Bank_Deposite bd3;

    std::cout << "===== Integer Interest Rate =====\n";
    bd1.display();

    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "===== Floating Interest Rate =====\n";
    bd2.display();

    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "===== Default Constructor =====\n";
    bd3.display();

    std::this_thread::sleep_for(std::chrono::seconds(3));

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
  }

  return EXIT_SUCCESS;
}
