class Solution
{
private:
    int mod = 1e9 + 7;

public:
    // Function to count number of ways to reach the nth stair.
    int memo(int n, vector<int> &dp)
    {
        if (dp[n] != -1)
        {
            return dp[n] % mod;
        }

        if (n <= 2)
            return dp[n] = n % mod;

        return dp[n] = (memo(n - 1, dp) % mod + memo(n - 2, dp) % mod) % mod;
    }
    int tab(int n)
    {
        vector<int> dp(n + 1, -1);

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i < n + 1; i++)
        {
            dp[i] = (dp[i - 1] % mod + dp[i - 2] % mod) % mod;
        }

        return dp[n];
    }

    int spaceOpt(int n)
    {
        int prev2 = 1;
        int prev = 1;

        for (int i = 2; i < n + 1; i++)
        {
            int cur_i = prev2 + prev;
            prev2 = prev;
            prev = cur_i;
        }

        return prev;
    }

    int countWays(int n)
    {
        // Memoization
        // vector<int> dp(n + 1, -1);
        // return memo(n, dp) % mod;

        // Tab                  TC: O(N)
        //                      SC: O(N)
        // return tab(n) % mod;

        // Space Optimized      TC: O(N)
        //                      SC: O(1)
        return spaceOpt(n) % mod;
    }
};

#include <bits/stdc++.h>
using namespace std;
int main()
{

    return 0;
}