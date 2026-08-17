#include <cstring>
#include <iostream>

struct Test {
    int name;
    char str[20];
};

int main() {
    Test *t = new Test;
    t->name = 843920;
    std::strcpy(t->str, "rnekjlrfe");

    std::cout << t->name << std::endl;
    std::cout << t->str << std::endl;
    delete t;
    return EXIT_SUCCESS;
}
