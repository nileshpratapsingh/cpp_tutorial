#include "utils.h"

class Student {
    protected:
        u64 roll_no;

    public:
        void set_number(u64 a) { roll_no = a; }
        void print_number(void) {
            std::cout << "Your Roll No. is : " << roll_no << std::endl;
        }
};
class Test : virtual public Student {
    protected:
        f64 maths, physics;

    public:
        void set_marks(f64 m, f64 p) {
            maths = m;
            physics = p;
        }
        void print_marks(void) {
            std::cout << "THe Marks of Maths are :" << maths << std::endl;
            std::cout << "THe Marks of Physics are :" << physics << std::endl;
        }
};
class Sports : virtual public Student {
    protected:
        f64 score;

    public:
        void set_score(f64 a) { score = a; }
        void display_score(void) {
            std::cout << "Your Score is :" << score << std::endl;
        }
};
class Result : public Test, public Sports {
    private:
        u64 a;
        f64 b, c, d;

    public:
        Result() {}
        Result(u64 roll, f64 math, f64 physics, f64 score) {
            a = roll;
            b = math;
            c = physics;
            d = score;
        }
        void run(void) {
            set_score(d);
            set_number(a);
            set_marks(b, c);
            print_number();
            print_marks();
            display_score();
        }
};

int main() {
    utils::initRandom();
    while (true) {
        u64 roll_no = utils::randomInt(10000);
        f64 math = utils::randomFloat(100), physics = utils::randomFloat(100),
            score = utils::randomFloat(100);
        Result *r = new Result(roll_no, math, physics, score);
        r->run();
        std::this_thread::sleep_for(std::chrono::seconds(3));
        system("clear");
    }
    return EXIT_SUCCESS;
}
