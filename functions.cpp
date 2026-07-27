#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>

using namespace std;

int print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << " " << arr[i];
    }
    return 0;
}

int main (){
    int arr[10] = {1,3,4,5,6,7,89,9,5,6,};
    print_array(arr,10);
    return 0;
}
