#include "utils.h"

// runtime polymorphism

class Base {
    public:
        u64 var_base = 6546453;
        virtual void display(void) const {
            std::cout << "The value of the base variable is :" << var_base << std::endl;
        }
        virtual ~Base(){}
};
class Derived : public Base {
    u64 var_derived = 4076732;

    public:
    void display(void) const {
        std::cout << "Derived class." << std::endl;
        std::cout << "The value of the base variable is :" << var_base << std::endl;
        std::cout << "The value of the derived variable is :" << var_derived
            << std::endl;
    }
};

int main() {
    Base *base_class_pointer = new Derived;
    /*
       This is called late binding.
       */
    base_class_pointer->display();

    Derived *derived_class_pointer = new Derived;
    derived_class_pointer->display();

    delete base_class_pointer;
    delete derived_class_pointer;
    return EXIT_SUCCESS;
}
