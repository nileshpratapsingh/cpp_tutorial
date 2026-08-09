#include "utils.h"

class Base1 {
    protected:
        int u1;

    public:
        void set_data(int a) { u1 = a; }
};

class Base2 {
    protected:
        int u2;

    public:
        void set_data(int a) { u2 = a; }
};

class Derived : public Base1, public Base2 {
    public:
        void display(void);
};

void Derived::display(void) {
    std::cout << "The value of base 1 is :" << u1 << std::endl;
    std::cout << "The value of base 2 is :" << u2 << std::endl;
}

int main() {
    Derived d1;
    d1.Base1::set_data(34);
    d1.Base2::set_data(45);
    d1.display();
    return EXIT_SUCCESS;
}
