#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mod = 1e9 + 7;
    int recur(int i, int sum, vector<int> &arr)
    {

        if (i == 0)
        {
            if (sum == 0 && arr[0] == 0)
                return 2;
            if (sum == 0)
                return 1;
            return 0;
        }

        int pick = (arr[i] <= sum) ? recur(i - 1, sum - arr[i], arr) % mod : 0;
        int notPick = recur(i - 1, sum, arr) % mod;

        return (pick + notPick) % mod;
    }
    int memo(int i, int sum, vector<int> &arr, vector<vector<int>> &dp)
    {

        if (dp[i][sum] != -1)
        {
            return dp[i][sum];
        }

        if (i == 0)
        {
            if (sum == 0 && arr[0] == 0)
                return 2;
            if (arr[0] == sum || sum == 0)
                return 1;
            return 0;
        }

        int pick = (arr[i] <= sum) ? memo(i - 1, sum - arr[i], arr, dp) % mod : 0;
        int notPick = memo(i - 1, sum, arr, dp) % mod;

        return dp[i][sum] = (pick + notPick) % mod;
    }
    int tab(int n, vector<int> &arr, int sum)
    {
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
                dp[i][0] = 2;
            else
                dp[i][0] = 1;
        }
        if (arr[0] <= sum && arr[0] != 0)
            dp[0][arr[0]] = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {

                int notPick = dp[i - 1][j];
                int pick = (arr[i] <= j) ? dp[i - 1][j - arr[i]] % mod : 0;

                dp[i][j] = (notPick + pick) % mod;
            }
        }

        return dp[n - 1][sum] % mod;
    }

    int spaceOpt(int n, vector<int> &arr, int sum)
    {
        vector<int> prev(sum + 1, 0), curr(sum + 1, 0);

        if (arr[0] == 0)
        {
            prev[0] = 2;
        }
        else
        {
            prev[0] = 1;
        }
        if (arr[0] <= sum && arr[0] != 0)
            prev[arr[0]] = 1;

        curr = prev;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {

                int notPick = prev[j] % mod;
                int pick = (arr[i] <= j) ? prev[j - arr[i]] % mod : 0;

                curr[j] = (notPick + pick) % mod;
            }
            prev = curr;
        }

        return prev[sum] % mod;
    }

    int countPartitions(int n, int d, vector<int> &arr)
    {
        // Code here

        int totSum = 0;
        for (auto it : arr)
        {
            totSum += it;
        }

        // s1 + s2  = totSum
        // s1-s2  = d
        // 2s1=  totSum + d
        // s1 = (totSum + d)/2
        // Edge Cases
        /*As the array elements are positive integers including zero, we don’t want to find the case when S2 is
        negative or we can say that totSum is lesser than D, therefore if totSum<D, we simply return 0.
        S2 can’t be a fraction, as all elements are integers, therefore if totSum – D is odd, we can return 0.
        */
        if (totSum - d < 0)
            return 0;

        if ((totSum - d) % 2 == 1)
            return 0;

        // Target (s2)
        int target = (totSum + d) / 2;

        // Recursion                      TC : O(2^N), SC : O(N)
        // return recur(n-1,target,arr);

        // Memoization
        // vector<vector<int>> dp (n,vector<int>(target+1,-1));
        // return memo(n-1,target,arr,dp);

        // Tabulation
        // return tab(n,arr,target);

        // SpaceOpt
        return spaceOpt(n, arr, target);
    }
};
int main()
{

    return 0;
}