#include "utils.h"

class Student {
protected:
    int roll_number;

public:
    void set_roll_number(int r);
    void get_roll_number(void);
};

void Student::set_roll_number(int r) {
    roll_number = r;
}

void Student::get_roll_number(void) {
    std::cout << "The Roll Number is: " << roll_number << std::endl;
}


class Exam : public Student {
protected:
    float maths;
    float physics;

public:
    float total = 200.0f;

    void set_marks(float, float);
    void get_marks(void);
};

void Exam::set_marks(float a, float b) {
    maths = a;
    physics = b;
}

void Exam::get_marks(void) {
    std::cout << "The marks of maths is: " << maths << std::endl;
    std::cout << "The marks of physics is: " << physics << std::endl;
}


class Result : public Exam {
protected:
    float percentage;
    float average;

public:
    void set_percentage(void);
    void calculate_average(void);
    void display(void);
};

void Result::set_percentage(void) {
    float given = maths + physics;

    percentage = (given / total) * 100.0f;
}

void Result::calculate_average(void) {
    average = (maths + physics) / 2.0f;
}

void Result::display(void) {
    std::cout << "Your Percentage is: " << percentage << "%" << std::endl;
    std::cout << "Your Average is: " << average << std::endl;
}


int main() {

    Result r1;

    r1.set_roll_number(458790);
    r1.set_marks(65.34f, 78.34f);

    r1.get_roll_number();
    r1.get_marks();

    r1.set_percentage();
    r1.calculate_average();

    r1.display();

    return EXIT_SUCCESS;
}
