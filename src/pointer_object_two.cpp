#include "utils.h"

class Shop {
    private:
        std::string id;
        u64 price, a, b;

    public:
        Shop(void) {}
        Shop(u64 a, u64 b) : id(utils::random_id_gen(20)), price(a), a(a), b(b) {
            std::cout << std::endl << "The Shop Id is : " << id << std::endl;
            std::cout << "The Shop Price of this item is : " << price << std::endl;
        }
        void get_data(void) {
            std::cout << "The value of a and b is :" << a << " " << b << std::endl;
        }
        std::string get_id(void) { return id; }
};

int main() {
    utils::initRandom();

    u64 a, b;
    std::vector<Shop *> Shops;

    for (u64 i = 0; i < 5; i++) {
        a = utils::randomInt(100);
        b = utils::randomInt(100);
        Shop *shop = new Shop(a, b);

        Shops.push_back(shop);
        Shops[i]->get_data();

        delete shop;
        std::cout << "The object with ID: " << Shops[i]->get_id() << " is deleted!!"
            << std::endl;
    }

    return EXIT_SUCCESS;
}
