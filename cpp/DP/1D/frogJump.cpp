#include <bits/stdc++.h>
using namespace std;
int main()
{
    return 0;
}

class Solution
{
public:
    int Memo(int i, vector<int> &heights, vector<int> &dp)
    {
        if (i == 0)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int one = abs(heights[i] - heights[i - 1]) + Memo(i - 1, heights, dp);
        int two = INT_MAX;
        if (i > 1)
            two = abs(heights[i] - heights[i - 2]) + Memo(i - 2, heights, dp);

        return dp[i] = min(one, two);
    }
    int tabulation(int n, vector<int> &heights)
    {
        vector<int> dp(n + 1, -1);
        dp[0] = 0;

        for (int i = 1; i < n + 1; i++)
        {
            int one = abs(heights[i] - heights[i - 1]) + dp[i - 1];
            int two = INT_MAX;
            if (i > 1)
                two = abs(heights[i] - heights[i - 2]) + dp[i - 2];

            dp[i] = min(one, two);
        }

        return dp[n];
    }

    int spaceOpt(int n, vector<int> &heights)
    {
        int prev = 0;
        int prev2 = 0;
        for (int i = 1; i < n + 1; i++)
        {
            int one = prev + abs(heights[i] - heights[i - 1]);
            int two = INT_MAX;
            if (i > 1)
                two = prev2 + abs(heights[i] - heights[i - 2]);

            int curr = min(one, two);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

    int minimumEnergy(vector<int> &height, int n)
    {
        // Code here

        // Memoization                 TC: O(N)
        //                             SC: O(N)
        // vector<int>  dp(n+1,-1);
        // return Memo(n-1,height,dp);

        // Tabulation                  TC: O(N)
        //                             SC: O(N
        // return tabulation(n-1,height);

        // Space Optimized             TC: O(N)
        //                             SC: O(1)
        return spaceOpt(n - 1, height);
    }
};