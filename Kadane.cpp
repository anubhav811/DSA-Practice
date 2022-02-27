// Kadane's algorithm
// O(n)

#include <iostream>
using namespace std;
int main()
{
    int arr[] = {-1, -2, -3, -4, -5, -6};
    int n = sizeof(arr) / sizeof(arr[0]);
    // Kadane's algorithm
    int curr = 0;
    int maxSum = 0;
    bool hasPositives = false;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] >= 0)
        {
            hasPositives = true;
            break;
        }
    }

    if (hasPositives)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            curr += nums[i];
            if (curr < 0)
                curr = 0;
            else if (curr > maxSum)
                maxSum = curr;
        }
        return maxSum;
    }
    else
    {
        return *max_element(nums.begin(), nums.end());
    }

    return 0;
}