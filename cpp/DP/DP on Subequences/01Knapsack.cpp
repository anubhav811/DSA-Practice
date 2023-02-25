#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int spaceOptSingleArr(int n, int w, int wt[], int val[])
    {
        vector<int> prev(w + 1, 0);

        for (int j = wt[0]; j <= w; j++)
        {
            prev[j] = val[0];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = w; j >= 0; j--)
            {
                int notTake = prev[j];
                int take = (wt[i] <= j) ? val[i] + prev[j - wt[i]] : 0;
                prev[j] = max(take, notTake);
            }
        }

        return prev[w];
    }
    int spaceOptNormal(int n, int w, int wt[], int val[])
    {

        vector<int> prev(w + 1, 0), curr(w + 1, 0);

        for (int j = wt[0]; j <= w; j++)
        {
            prev[j] = val[0];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                int notTake = prev[j];
                int take = (wt[i] <= j) ? val[i] + prev[j - wt[i]] : 0;
                curr[j] = max(take, notTake);
            }
            prev = curr;
        }

        return prev[w];
    }
    int tab(int n, int w, int wt[], int val[])
    {
        vector<vector<int>> dp(n, vector<int>(w + 1, 0));
        for (int j = wt[0]; j <= w; j++)
        {
            dp[0][j] = val[0];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= w; j++)
            {
                int take = (wt[i] <= j) ? val[i] + dp[i - 1][j - wt[i]] : 0;
                int notTake = dp[i - 1][j];

                dp[i][j] = max(take, notTake);
            }
        }
        return dp[n - 1][w];
    }
    int memo(int i, int w, int wt[], int val[], vector<vector<int>> &dp)
    {

        if (i == 0)
        {
            if (wt[0] <= w)
                return val[0];
            else
                return 0;
        }

        if (dp[i][w] != -1)
            return dp[i][w];

        int take = (wt[i] <= w) ? val[i] + memo(i - 1, w - wt[i], wt, val, dp) : 0;
        int notTake = 0 + memo(i - 1, w, wt, val, dp);

        return dp[i][w] = max(take, notTake);
    }
    int recur(int i, int w, int wt[], int val[])
    {

        if (i == 0)
        {
            if (wt[i] <= w)
                return val[i];
            else
                return 0;
        }
        int take = (wt[i] <= w) ? val[i] + recur(i - 1, w - wt[i], wt, val) : 0;
        int notTake = 0 + recur(i - 1, w, wt, val);

        return max(take, notTake);
    }
    int knapSack(int w, int wt[], int val[], int n)
    {

        // Recursion                         TLE             TC: 2^N
        //                                                   SC: O(N)
        // return recur(n-1,w,wt,val);

        // Memoization                                       TC :   O(N*W)
        //                                                   SC :   O(N*W) + O(N)
        // vector<vector<int>> dp(n,vector<int>(w+1,-1));
        // return memo(n-1,w,wt,val,dp);

        // Tabulation                                        TC :   O(N*W)
        //                                                   SC :   O(N*W) + O(N)
        // return tab(n,w,wt,val);

        // Space Optimization - 2 Rows                       TC :   O(N*W)
        //                                                   SC :   O(N) + O(N)
        // return spaceOptNormal(n,w,wt,val);

        // Space Optimization - 1 Row                        TC :   O(N*W)
        //                                                   SC :   O(N)
        return spaceOptSingleArr(n, w, wt, val);
    }
};
int main()
{

    return 0;
}
