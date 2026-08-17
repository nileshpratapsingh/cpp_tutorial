#include "utils.h"

class A {
    private:
        u64 a;

    public:
        A(void) {}
        A(u64 a) : a(utils::randomInt(100)) {
            std::cout << "The value of a + a is: " << a + a << std::endl;
        }
        void set_data(u64 a) {
            /*
               "this" is the keyword which is a pointer to the object which is beign
               created at the moment, which means the every object that has been created
               have its own diffrent address this pointer.
               */
            this->a = a;
            std::cout << "The value of this->a is: " << this->a << std::endl;
            std::cout << "The value of a is: " << a << std::endl;
        }
        /*
           "const" keyword means the member function cannot modify the object
           */
        void get_data() const {
            std::cout << "The value of a is: " << a << std::endl;
        }
        u64 *get_value(u64 b) { return new u64{10 + b}; }
};

int main() {
    utils::initRandom();
    std::cout << "The value of a after initializing constructor." << std::endl;
    A *a = new A(10);
    a->get_data();
    std::cout << "The value of a after initializing the set_data." << std::endl;
    a->set_data(utils::randomInt(100));
    a->get_data();
    std::cout << "The value of b after initializing constructor." << std::endl;
    A *b = new A(20);
    b->get_data();
    std::cout << "The value of b after initializing the set_data." << std::endl;
    b->set_data(utils::randomInt(100));
    b->get_data();
    std::cout << *b->get_value(30) << std::endl;
    return EXIT_SUCCESS;
}
