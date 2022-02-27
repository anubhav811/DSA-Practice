// O(n^3)

#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum;
    int max = INT8_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
                if (sum > max)
                {
                    max = sum;
                }
            }
        }
    }
    cout << "Maximum contiguous sum is " << max;

    return 0;
}
