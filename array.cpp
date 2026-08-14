#include "utils.h"

std::pair<u64, u64> *get_max_min(u64 nums[], u64 size) {
    u64 max = std::numeric_limits<u64>::min();
    u64 min = std::numeric_limits<u64>::max();
    for (u64 i = 0; i < size; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
        if (nums[i] < min) {
            min = nums[i];
        }
    }

    return new std::pair<u64, u64>{max, min};
}

int main() {
    utils::initRandom();
    u64 size = utils::randomInt(1000);

    u64 arr[1000];

    for (u64 i = 0; i < size; i++) {
        arr[i] = utils::randomInt(5762);
    }

    system("cls");
    utils::print_array(arr, size, true);

    std::pair<u64, u64> *result = get_max_min(arr, size);

    std::cout << "The max value in array is: " << result->first << std::endl;
    std::cout << "The min value in array is: " << result->second << std::endl;

    delete result;
    return 0;
}
