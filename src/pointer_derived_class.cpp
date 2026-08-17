#include "utils.h"

class Base {
    public:
        u64 var_base = 6546453;
        void display1(void) const {
            std::cout << "The value of the base variable is :" << var_base << std::endl;
        }
};
class Derived : public Base {
    u64 var_derived = 4076732;

    public:
    void display2(void) const {
        std::cout<<"Derived class."<<std::endl;
        std::cout << "The value of the base variable is :" << var_base << std::endl;
        std::cout << "The value of the derived variable is :" << var_derived
            << std::endl;
    }
};

int main() {
    Base *base_class_pointer;
    Derived derived_obj;
    /*
      This is called late binding.
     */
    base_class_pointer = &derived_obj;
    base_class_pointer->display1();

    Derived *derived_class_pointer;
    derived_class_pointer = &derived_obj;
    derived_class_pointer->display1();
    derived_class_pointer->display2();
    return EXIT_SUCCESS;
}
