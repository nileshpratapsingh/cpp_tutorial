#include "utils.h"

class shop {
    public:
        std::string itemId[100];
        size_t itemPrice[100];
        size_t counter;
        void initCounter(void) { counter = 0; }
        void setPrice(void);
        void getPrice(void) const;
};

void shop::setPrice() {
    itemId[counter] = utils::random_id_gen(20);
    itemPrice[counter] = utils::randomInt(700);
    counter++;
}

void shop::getPrice() const {
    for (size_t i = 0; i < counter; i++) {
        std::cout << "Price of your item " << i + 1 << " is: " << itemPrice[i]
            << " and "
            << "your itemId id is : " << itemId[i] << std::endl;
    }
}

int main() {
    utils::initRandom();
    shop s;
    s.initCounter();
    u64 n = utils::randomInt(20);

    printf("Hello.\n");

    for (u64 i = 0; i < n; i++) {
        s.setPrice();
    }
    s.getPrice();

    return EXIT_SUCCESS;
}
