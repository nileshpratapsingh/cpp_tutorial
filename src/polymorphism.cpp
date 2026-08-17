#include "utils.h"

class Number {
    private:
        int value;

    public:
        Number(int value) { this->value = value; }

        int add(int a) { return value + a; }

        int add(int a, int b) { return value + a + b; }

        Number operator+(const Number &other) {
            return Number(this->value + other.value);
        }

        void print() const { std::cout << "Value = " << value << '\n'; }
};

class Animal {
    public:
        virtual void sound() { std::cout << "Animal makes a sound\n"; }

        virtual ~Animal() {}
};

class Dog : public Animal {
    public:
        void sound() override { std::cout << "Dog barks\n"; }
};

class Cat : public Animal {
    public:
        void sound() override { std::cout << "Cat meows\n"; }
};

int main() {
    Number n(10);

    std::cout << "Function Overloading:\n";
    std::cout << n.add(20) << '\n';
    std::cout << n.add(20, 30) << '\n';

    std::cout << "\nOperator Overloading:\n";

    Number a(10);
    Number b(20);

    Number c = a + b;

    c.print();

    std::cout << "\nVirtual Function:\n";

    Animal *animal;

    Dog dog;
    Cat cat;

    animal = &dog;
    animal->sound();

    animal = &cat;
    animal->sound();

    std::cout << "\nVirtual Function with Pointer:\n";

    Animal *ptr1 = new Dog();
    Animal *ptr2 = new Cat();

    ptr1->sound();
    ptr2->sound();

    delete ptr1;
    delete ptr2;

    return 0;
}
