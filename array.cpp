#include "utils.h"

std::pair<int,int> get_max_min(int nums[], int size){
    int max = std::numeric_limits<int>::min();
    int min = std::numeric_limits<int>::max();
    for (int i = 0; i < size; i++)
    {
        if (nums[i] > max)
        {
            max = nums[i];
        }
        if (nums[i] < min)
        {
            min = nums[i];
        }
    }

    return {max, min};
}

int main(){

    int size;
    std::cout << "Enter size: ";
    std::cin >> size;

    int arr[100];

    for (int i = 0; i < size; i++)
    {
        std::cout << "Enter element " << i + 1 << ": ";
        std::cin >> arr[i];
    }

    print_array(arr, size);

    std::pair<int, int> result = get_max_min(arr, size);
    std::cout << "The max value in array is: " << result.first << std::endl;
    std::cout << "The min value in array is: " << result.second << std::endl;

    return 0;
}
