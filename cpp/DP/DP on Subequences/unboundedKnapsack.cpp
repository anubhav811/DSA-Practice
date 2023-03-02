#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int recur(int i, int W, int val[], int wt[])
    {
        if (i == 0)
        {
            return ((int)(W / wt[0])) * val[0];
        }

        int take = (wt[i] <= W) ? val[i] + recur(i, W - wt[i], val, wt) : INT_MIN;
        int nottake = recur(i - 1, W, val, wt);

        return max(take, nottake);
    }
    int memo(int i, int W, int val[], int wt[], vector<vector<int>> &dp)
    {

        if (dp[i][W] != -1)
            return dp[i][W];
        if (i == 0)
        {
            return ((int)(W / wt[0])) * val[0];
        }

        int take = (wt[i] <= W) ? val[i] + memo(i, W - wt[i], val, wt, dp) : INT_MIN;
        int nottake = memo(i - 1, W, val, wt, dp);

        return dp[i][W] = max(take, nottake);
    }

    int tab(int n, int W, int val[], int wt[])
    {

        vector<vector<int>> dp(n, vector<int>(W + 1, 0));

        for (int j = wt[0]; j <= W; j++)
        {
            dp[0][j] = ((int)(j / wt[0]) * val[0]);
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= W; j++)
            {

                int take = (wt[i] <= W) ? val[i] + dp[i][j - wt[i]] : INT_MIN;
                int nottake = dp[i - 1][j];

                dp[i][j] = max(take, nottake);
            }
        }

        return dp[n - 1][W];
    }

    // int spaceOpt(int n, int W, int val[] , int wt[]){
    //     vector<int> cur(W+1,0);

    //     //Base Condition

    //     for(int j=wt[0]; j<=W; j++){
    //         cur[j] = ((int)j/wt[0]) * val[0];
    //     }

    //     for(int i =1; i<n; i++){
    //         for(int j=W; j>=0; j--){

    //             int notTaken = cur[j];

    //             int taken = INT_MIN;
    //             if(wt[i] <= j)
    //                 taken = val[i] + cur[j - wt[i]];

    //             cur[j] = max(notTaken, taken);
    //         }
    //     }

    //     return cur[W];
    // }

    int knapSack(int N, int W, int val[], int wt[])
    {
        // Recursion                                TLE     TC: Exp
        //                                                  SC: O(W)
        // return recur(N-1,W,val,wt);

        // Memoization                                      TC: O(N*W)
        //                                                  SC: O(N*W) + O(N)
        // vector<vector<int>> dp(N,vector<int>(W+1,-1));
        // return memo(N-1,W,val,wt,dp);

        // Tabulation                                       TC: O(N*W)
        //                                                  SC: O(N*W)
        return tab(N, W, wt, val);

        // Space Opt                                        TC: O(N*W)
        //                                                  SC: O(W)
        // Incorrect Answer
        // return spaceOpt(N,W,wt,val);
    }
};
int main()
{

    return 0;
}