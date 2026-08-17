#include "utils.h"

class Employee {
    u64 id;
    static u64 count;

    public:
    void setId(void);
    void getId(void);
};

void Employee::setId() {
    std::cout << "Enter the ID: ";
    if (!(std::cin >> id)) {
        std::cout << "Id should be an integer." << std::endl;
        std::exit(EXIT_FAILURE);
    }
    count++;
}

void Employee::getId(void) { std::cout << "The Id is: " << id << std::endl; }

u64 Employee::count = 0;

int main() {
    std::vector<Employee *> a;

    for (u64 i = 0; i < 4; i++) {
        Employee *e = new Employee;
        a.push_back(e);
        a[i]->setId();
    }

    for (u64 i = 0; i < 4; i++) {
        a[i]->getId();
    }

    for (u64 i = 0; i < 4; i++) {
        delete a[i];
    }
}
