#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int spaceOpt(int n, int amount, vector<int> &coins)
    {
        vector<int> prev(amount + 1, 0), cur(amount + 1, 0);

        for (int j = 0; j <= amount; j++)
        {
            if (j % coins[0] == 0)
                prev[j] = 1;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                int notTake = prev[j];
                int take = (coins[i] <= j) ? cur[j - coins[i]] : 0;

                cur[j] = take + notTake;
            }
            prev = cur;
        }
        return prev[amount];
    }
    int tab(int n, int amount, vector<int> &coins)
    {
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for (int j = 0; j <= amount; j++)
        {
            if (j % coins[0] == 0)
                dp[0][j] = 1;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                int take = (coins[i] <= j) ? dp[i][j - coins[i]] : 0;
                int notTake = dp[i - 1][j];

                dp[i][j] = take + notTake;
            }
        }

        return dp[n - 1][amount];
    }
    int memo(int i, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {

        if (i == 0)
        {
            if (amount % coins[0] == 0)
                return 1;
            else
                return 0;
        }

        if (dp[i][amount] != -1)
        {
            return dp[i][amount];
        }

        int take = (coins[i] <= amount) ? memo(i, amount - coins[i], coins, dp) : 0;
        int notTake = memo(i - 1, amount, coins, dp);

        return take + notTake;
    }
    int recur(int i, int amount, vector<int> &coins)
    {
        if (i == 0)
        {
            if (amount % coins[0] == 0)
                return 1;
            else
                return 0;
        }

        int take = (coins[i] <= amount) ? recur(i, amount - coins[i], coins) : 0;
        int nottake = recur(i - 1, amount, coins);

        return take + nottake;
    }
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();

        // Recursion              TLE        TC : expo
        //                                   SC : O(amount)
        // return recur(n-1,amount,coins);

        // Memoization            TLE        TC : O(N*T)
        //                                   SC : O(N*T) + O(N)
        // vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        // return memo(n-1,amount,coins,dp);

        // Tabulation                        TC: O(N*T)
        //                                   SC: O(N*T)
        // return tab(n,amount,coins);

        // Space Optimized                   TC: O(N*T)
        //                                   SC: O(N*T)
        return spaceOpt(n, amount, coins);
    }
};
int main()
{

    return 0;
}