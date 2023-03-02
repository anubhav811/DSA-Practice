#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int spaceOpt(int n, int amount, vector<int> &coins)
    {
        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);

        for (int j = 0; j <= amount; j++)
        {
            if (j % coins[0] == 0)
                prev[j] = j / coins[0];
            else
                prev[j] = 1e9;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {

                int notTake = prev[j];
                int take = (coins[i] <= j) ? (1 + curr[j - coins[i]]) : 1e9;

                curr[j] = min(notTake, take);
            }
            prev = curr;
        }

        return (prev[amount] >= 1e9) ? -1 : prev[amount];
    }
    int tab(int n, int amount, vector<int> &coins)
    {

        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int j = 0; j <= amount; j++)
        {
            if (j % coins[0] == 0)
                dp[0][j] = j / coins[0];
            else
                dp[0][j] = 1e9;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {

                int notTake = dp[i - 1][j];
                int take = (coins[i] <= j) ? (1 + dp[i][j - coins[i]]) : 1e9;

                dp[i][j] = min(notTake, take);
            }
        }

        return (dp[n - 1][amount] >= 1e9) ? -1 : dp[n - 1][amount];
    }
    int memo(int i, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {

        if (dp[i][amount] != -1)
        {
            return dp[i][amount];
        }
        if (i == 0)
        {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            else
                return 1e9;
        }

        int take = (coins[i] <= amount) ? 1 + memo(i, amount - coins[i], coins, dp) : 1e9;
        int notTake = memo(i - 1, amount, coins, dp);

        return dp[i][amount] = min(take, notTake);
    }
    int recur(int i, int amount, vector<int> &coins)
    {

        if (i == 0)
        {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            else
                return 1e9;
        }

        int take = (coins[i] <= amount) ? 1 + recur(i, amount - coins[i], coins) : 1e9;
        int nottake = recur(i - 1, amount, coins);

        return min(take, nottake);
    }
    int coinChange(vector<int> &coins, int amount)
    {

        int n = coins.size();
        // Recursion              TC : not (2^n) but way more than that ~ exponential
        //                        SC : O(N)
        // int ans = recur(n-1,amount,coins);
        // return (ans>=1e9) ? -1 : ans;

        // Memoization
        // vector<vector<int>> dp(n,vector<int>(amount+1,-1));       TC: O(N*T)
        //                                                           SC: O(N*T) + O(N)
        // int ans = memo(n-1,amount,coins,dp);
        // return (ans>=1e9) ? -1 : ans;

        // Tabulation                                                TC: O(N*T)
        //                                                           SC: O(N*T)
        // return tab(n,amount,coins);

        // Space Optimized                                           TC: O(N*T)
        //                                                           SC: O(T)
        return spaceOpt(n, amount, coins);
    }
};
int main()
{

    return 0;
}