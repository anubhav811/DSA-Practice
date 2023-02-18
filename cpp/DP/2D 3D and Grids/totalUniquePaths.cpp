#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int recur(int i, int j)
    {
        if (i == 0 && j == 0)
            return 1;

        if (i < 0 || j < 0)
            return 0;

        int up = recur(i - 1, j);
        int left = recur(i, j - 1);

        return up + left;
    }

    int memo(int i, int j, vector<vector<int>> &dp)
    {

        if (i == 0 && j == 0)
            return 1;

        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = memo(i - 1, j, dp);
        int left = memo(i, j - 1, dp);

        return dp[i][j] = up + left;
    }

    int tab(int n, int m)
    {
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[0][0] = 1;
                    continue;
                }

                int up = 0;
                int left = 0;

                if (i > 0)
                    up = dp[i - 1][j];

                if (j > 0)
                    left = dp[i][j - 1];

                dp[i][j] = up + left;
            }
        }
        return dp[n - 1][m - 1];
    }

    int spaceOpt(int n, int m)
    {
        vector<int> prev(m, 0);
        for (int i = 0; i < n; i++)
        {
            vector<int> temp(m, 0);
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                {
                    temp[j] = 1;
                    continue;
                }

                int up = 0;
                int left = 0;

                if (i > 0)
                    up = prev[j];
                if (j > 0)
                    left = temp[j - 1];

                temp[j] = up + left;
            }
            prev = temp;
        }

        return prev[m - 1];
    }

    int NumberOfPath(int a, int b)
    {
        // Recursion TLE            TC : O(2^(m*n))
        //                          SC : path length m-1+n-1
        // return recur(a-1,b-1);

        // Memo                     TC : O(M*N)
        //                          SC : O((N-1)+(M-1)) + O(M*N)
        // vector<vector<int>> dp(a,vector<int>(b,-1));
        // return memo(a-1,b-1,dp);

        // Tab                      TC : O(M*N)
        //                          SC : O(M*N)
        // return tab(a, b);

        // Space optimized          TC: O(M*N)
        //                          SC: O(N)
        return spaceOpt(a, b);
    }
};

int main()
{

    return 0;
}