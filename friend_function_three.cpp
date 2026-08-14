#include "utils.h"

class Y;
class X {
    u64 x;

    public:
    void setData(u64 a);
    void display(void);
    friend u64 add(X, Y);
};
class Y {
    u64 y;

    public:
    void setData(u64 a);
    void display(void);
    friend u64 add(X, Y);
};
void X::setData(u64 a) { x = a; }
void Y::setData(u64 a) { y = a; }
void X::display(void) { std::cout << "The Number is : " << x << std::endl; }
void Y::display(void) { std::cout << "The Number is : " << y << std::endl; }
u64 add(X x1, Y y1) { return (x1.x + y1.y); }
int main() {
    X a;
    Y b;
    u64 n1, n2;
    utils::initRandom();
    n1 = utils::randomInt(100);
    n2 = utils::randomInt(100);
    a.setData(n1);
    b.setData(n2);
    a.display();
    b.display();
    u64 res = add(a, b);
    std::cout << "The Sum is : " << res << std::endl;
    return EXIT_SUCCESS;
}
