#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool spaceOpt(int N, int target, int arr[], vector<bool> &prev)
    {
        vector<bool> curr(target + 1, false);

        prev[0] = curr[0] = true;

        for (int i = 1; i < N; i++)
        {
            for (int j = 1; j <= target; j++)
            {

                bool pick = (arr[i] <= j) ? prev[j - arr[i]] : false;
                bool notPick = prev[j];

                curr[j] = pick || notPick;
            }
            prev = curr;
        }

        return prev[target];
    }
    bool tab(int N, int totSum, int arr[], vector<vector<bool>> &dp)
    {

        for (int i = 0; i < N; i++)
            dp[i][0] = true;

        if (arr[0] <= totSum)
            dp[0][totSum] = true;

        for (int i = 1; i < N; i++)
        {
            for (int j = 1; j < totSum + 1; j++)
            {
                bool pick = (arr[i] <= j) ? dp[i - 1][j - arr[i]] : false;
                bool notPick = dp[i - 1][j];

                dp[i][j] = pick || notPick;
            }
        }

        return dp[N - 1][totSum];
    }
    bool memo(int i, int target, int arr[], vector<vector<int>> &dp)
    {
        if (target == 0)
            return dp[i][target] = true;
        if (i == 0)
            return arr[0] == target;

        if (dp[i][target] != -1)
        {
            return dp[i][target];
        }

        bool pick = (arr[i] <= target) ? memo(i - 1, target - arr[i], arr, dp) : false;
        bool notPick = memo(i - 1, target, arr, dp);

        return dp[i][target] = pick || notPick;
    }

    bool recur(int i, int target, int arr[])
    {

        if (target == 0)
            return true;
        if (i == 0)
            return arr[i] == target;

        bool pick = (arr[i] <= target) ? recur(i - 1, target - arr[i], arr) : false;
        bool notpick = recur(i - 1, target, arr);

        return pick || notpick;
    }

    int minDifference(int arr[], int N)
    {

        int totalSum = 0;
        for (int i = 0; i < N; i++)
        {
            totalSum += arr[i];
        }

        int mini = 1e9;

        // Recursion                                                TC :, SC :
        // for (int i = 0; i <= totalSum; i++) {
        //     if (recur(N-1,i,arr) == true) {
        //       int diff = abs(i - (totalSum - i));
        //       mini = min(mini, diff);
        //     }
        //   }

        // Memoization                                               TC :O(N*totSum) +O(N) +O(N), SC : O(N*totSum) + O(N)
        // vector<vector<int >> dp (N,vector<int >(totalSum+1,-1));
        // for (int i = 0; i <= totalSum; i++) {
        //     bool bkchodi = memo(N-1,i,arr,dp);
        // }

        // for (int i = 0; i <= totalSum; i++) {
        //     if (dp[N-1][i] == true) {
        //       int diff = abs(i - (totalSum - i));
        //       mini = min(mini, diff);
        //     }
        // }

        // Tabulation                                                 TC :O(N*totSum) +O(N) +O(N), SC : O(N*totSum)
        // vector<vector<bool>> dp (N,vector<bool>(totalSum+1,false));
        // bool bkchodi = tab(N,totalSum,arr,dp);

        // for (int i = 0; i <= totalSum; i++) {
        //     if (dp[N-1][i] == true) {
        //       int diff = abs(i - (totalSum - i));
        //       mini = min(mini, diff);
        //     }
        // }

        // // Space Optimizaton                                        TC :O(N*totSum) +O(N) +O(N), SC : O(totSum)
        vector<bool> prev(totalSum + 1, false);
        bool bkchodi = spaceOpt(N, totalSum, arr, prev);

        for (int i = 0; i <= totalSum; i++)
        {
            if (prev[i] == true)
            {
                int diff = abs(i - (totalSum - i));
                mini = min(mini, diff);
            }
        }

        return mini;
    }
};
int main()
{

    return 0;
}