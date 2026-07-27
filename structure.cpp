#include <iostream>
#include <cstring>

struct Test
{
    int name;
    char str[20];
};

int main()
{
    Test t;
    t.name = 843920;
    std::strcpy(t.str, "rnekjlrfe");

    std::cout << t.str << std::endl;
    return 0;
}
