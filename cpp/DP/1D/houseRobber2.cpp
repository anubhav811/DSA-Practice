#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long f(vector<int> &nums)
    {
        long long prev = nums[0];
        long long prev2 = 0;
        for (long long i = 1; i < nums.size(); i++)
        {
            long long pick = nums[i];
            if (i > 1)
                pick += prev2;
            long long notPick = 0 + prev;
            long long curi = max(pick, notPick);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
    // We take 1 time without last element and 2nd time without 1st element
    int rob(vector<int> &valueInHouse)
    {
        vector<int> temp1, temp2;

        long long n = valueInHouse.size();
        if (n == 1)
            return valueInHouse[0];

            // [1,2,3,4,5,6,24,43]

        for (long long i = 0; i < n; i++)
        {
            if (i != 0)
                temp1.push_back(valueInHouse[i]);
            if (i != n - 1)
                temp2.push_back(valueInHouse[i]);
        }
        return max(f(temp1), f(temp2));
    }
};
int main()
{

    vector<int> h = {2, 3, 2};
    Solution obj = Solution();
    cout << obj.rob(h);
}
