class Solution
{
public:
    int recur(vector<int> arr, int i)
    {

        // if we are anyhow reaching i = 0 , it means index 1 was not picked (because we dont take adjacent)
        // so we can pick i=0 element , coz 1 is not picked
        if (i == 0)
            return arr[i];
        // However lets say we had reached index =  1 and pick it, then on calling the next recursion we would have options to
        // reach 0 and -1
        // In case of zero we cant pick because it would be adjacent so zero is out of picture, but if we get a -1 or
        // any other negative value we can simply send back 0 i.e no effect on the sum
        if (i < 0)
        {
            return 0;
        }
        int pick = arr[i] + recur(arr, i - 2);
        int notpick = 0 + recur(arr, i - 1);

        return max(pick, notpick);
    }

    int memo(vector<int> arr, int i, vector<int> &dp)
    {

        if (i == 0)
            return arr[i];
        if (i < 0)
            return 0;

        if (dp[i] != -1)
        {
            return dp[i];
        }

        int pick = arr[i] + recur(arr, i - 2);
        int notpick = 0 + recur(arr, i - 1);

        return dp[i] = max(pick, notpick);
    }

    int tab(vector<int> arr, int n)
    {
        vector<int> dp(n + 1, -1);

        dp[0] = arr[0];

        for (int i = 1; i < n; i++)
        {
            int pick = arr[i];
            if (i > 1)
                pick += dp[i - 2];
            int notpick = 0 + dp[i - 1];

            dp[i] = max(pick, notpick);
        }

        return dp[n - 1];
    }

    int spaceOpt(vector<int> &arr)
    {
        int n = arr.size();
        int prev = arr[0]; // this is zero wala (agar i=1 hai , matlab usse just pehle wala isliye 'prev' )
        int prev2 = 0;     // this is negative wala (agar i=1 hai , usee pehle ke pehle wala isliye 'prev2')
        for (int i = 1; i < n; i++)
        {
            int take = arr[i];
            if (i > 1)
                take += prev2;
            int nottake = 0 + prev;

            int curr = max(take, nottake);

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }

    int FindMaxSum(vector<int> arr, int n)
    {
        // Recursion TLE
        // array and index passed
        // return recur(arr,n-1);

        // Memoization TLE                 TC : O(N)
        //                                 SC : O(N)
        // array ,dp and index passed
        // vector<int> dp(n+1,-1);
        // return memo(arr,n-1,dp);

        // DP Tabulation                   TC : O(N)
        //                                 SC : O(N)
        // array and size passed
        // return tab(arr);

        // Space Optimization              TC -> O(N)
        //                                 SC -> O(1)
        // array and size passed
        return spaceOpt(arr);
    }
};

#include <bits/stdc++.h>
using namespace std;
int main()
{

    return 0;
}