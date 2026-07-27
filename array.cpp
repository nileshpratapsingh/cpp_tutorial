#include <iostream>
#include <limits>
using namespace std;

pair<int,int> get_max_min(int nums[], int size)
{

    int max = std::numeric_limits<int>::min();
    int min = std::numeric_limits<int>::max();
    for (int i = 0; i < size; i++)
    {
        if (nums[i] > max)
        {
            max = nums[i];
        };

        if (nums[i] < min)
        {
            min = nums[i];
        };
    }

    return {max, min};
}

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << i + 1 << ": " << arr[i] << endl;
    }
}

int main()
{
    int size;
    cout << "Enter size: ";
    cin >> size;

    int arr[100];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    print_array(arr, size);

    pair<int, int> result = get_max_min(arr, size);
    cout << "The max value in array is: " << result.first << endl;
    cout << "The min value in array is: " << result.second << endl;

    return 0;

    // Free allocated memory
    // delete[] arr;

    return 0;
}
