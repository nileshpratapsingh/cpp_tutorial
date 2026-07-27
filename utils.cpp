// utils.cpp
#include "utils.h"

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "Element " << i + 1 << ": " << arr[i] << std::endl;
    }
}
