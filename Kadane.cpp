// Kadane's algorithm
// O(n)

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums = {-1, -2, -3, -4, -5, -6};
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
            {
                curr = 0;
            }
            else if (curr > maxSum)
            {
                maxSum = curr;
            }
        }
        cout << maxSum;
    }
    else
    {
        cout << *max_element(nums.begin(), nums.end());
    }
    return 0;
}