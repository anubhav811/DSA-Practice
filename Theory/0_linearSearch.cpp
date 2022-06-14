#include <iostream>
using namespace std;
int linearSearch(int arr[], int target)
{
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
        if (arr[i] == target)
            return i;
    return -1;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 2;
    int index = linearSearch(arr, target);
    if (index == -1)
        cout << "Element not found";
    else
        cout << "Element found at index " << index;
    return 0;
}