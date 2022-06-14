#include <iostream>
using namespace std;
// write a program for linear search in 2d array

void linearSearch2D(int arr[][10], int target)
{
    int row = sizeof(arr) / sizeof(arr[0]);
    int col = sizeof(arr[0]) / sizeof(arr[0][0]);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (arr[i][j] == target)
                cout << "Element found at index " << i << "," << j;
    return;
    cout << "Element not found";
}

int main()
{
    int arr[][10] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                     {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
                     {21, 22, 23, 24, 25, 26, 27, 28, 29, 30}};
    int target = 2;
    linearSearch2D(arr, target);
    return 0;
}
