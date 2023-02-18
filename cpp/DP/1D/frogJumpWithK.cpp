#include <bits/stdc++.h>
using namespace std;
int main()
{
    return 0;
}

class Solution
{
public:
    int recur(vector<int> &height, int i, int k)
    {
        if (i == 0)
            return 0;

        int cost = INT_MAX;
        for (int jump = 1; jump <= k; jump++)
        {
            // making sure index doesnt go negative
            if (i - jump >= 0)
            {
                int newCost = recur(height, i - jump, k) + abs(height[i] - height[i - jump]);
                cost = min(cost, newCost);
            }
        }
        return cost;
    }
    int memo(vector<int> &height, int i, int k, vector<int> &dp)
    {
        if (i == 0)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int cost = INT_MAX;
        for (int jump = 1; jump <= k; jump++)
        {
            // making sure index doesnt go negative
            if (i - jump >= 0)
            {
                int newCost = recur(height, i - jump, k) + abs(height[i] - height[i - jump]);
                cost = min(cost, newCost);
            }
        }
        return dp[i] = cost;
    }

    int tab(vector<int> &height, int n, int k)
    {

        vector<int> dp(n + 1, -1);
        dp[0] = 0;

        for (int i = 1; i < n + 1; i++)
        {
            int cost = INT_MAX;
            for (int jump = 1; jump <= k; jump++)
            {
                if (i - jump >= 0)
                {
                    int newCost = dp[i - jump] + abs(height[i] - height[i - jump]);
                    cost = min(newCost, cost);
                }
                dp[i] = cost;
            }
        }

        return dp[n - 1];
    }
    int minimizeCost(vector<int> &height, int n, int k)
    {

        // 1.Recursion  ->          TC = O(N*k)
        //                          SC = O(N) {recursion stack space}
        // TLE
        // return recur(height,n-1,k);

        // 2 . Memoization->        TC = O(N*k)
        //                          SC = O(2*N) = O(N) {recursion stack space, dp array}
        // TLE
        // vector<int> dp(n+1,-1);
        // return memo(height,n-1,k,dp);

        // 3 . Tabulation ->        TC= O(N*K)
        //                         SC = O(N)
        return tab(height, n, k);
    }
};
