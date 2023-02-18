#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    const int mod = 1e9 + 7;

    int recur(int i, int j, vector<vector<int>> &grid)
    {

        if (i < 0 or j < 0)
            return 0;

        if (i == 0 and j == 0 and grid[i][j] == 0)
            return 1;

        if (grid[i][j] == 1)
            return 0;

        int up = recur(i - 1, j, grid);
        int left = recur(i, j - 1, grid);

        return up + left;
    }

    int memo(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (i < 0 or j < 0)
            return 0;

        if (i == 0 and j == 0 and grid[i][j] == 0)
            return 1;

        if (grid[i][j] == 1)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = (memo(i - 1, j, grid, dp) + memo(i, j - 1, grid, dp)) % mod;
    }

    int tab(int n, int m, vector<vector<int>> grid)
    {
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0 && grid[i][j] == 0)
                {
                    dp[0][0] = 1;
                    continue;
                }
                if (grid[i][j] == 1)
                {
                    dp[i][j] = 0;
                    continue;
                }

                int up = 0;
                int left = 0;

                if (i > 0)
                    up = dp[i - 1][j] % mod;

                if (j > 0)
                    left = dp[i][j - 1] % mod;
                dp[i][j] = (up + left) % mod;
            }
        }
        return dp[n - 1][m - 1] % mod;
    }

    int spaceOpt(int n, int m, vector<vector<int>> grid)
    {
        vector<int> prev(m, 0);

        for (int i = 0; i < n; i++)
        {
            vector<int> temp(m, 0);
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0 && grid[i][j] == 0)
                {
                    temp[j] = 1;
                    continue;
                }
                if (grid[i][j] == 1)
                {
                    temp[j] = 0;
                    continue;
                }

                int up = 0;
                int left = 0;

                if (i > 0)
                    up = prev[j] % mod;

                if (j > 0)
                    left = temp[j - 1] % mod;
                temp[j] = (up + left) % mod;
            }
            prev = temp;
        }
        return prev[m - 1] % mod;
    }

    int totalWays(int n, int m, vector<vector<int>> &grid)
    {

        // Recursion TLE            TC : O(2^(m*n))
        //                          SC : path length m-1+n-1
        // return recur(n-1,m-1,grid);

        // Memo                     TC : O(M*N)
        //                          SC : O((N-1)+(M-1)) + O(M*N)
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return memo(n-1,m-1,grid,dp);

        // Tab                      TC : O(M*N)
        //                          SC : O(M*N)
        // return tab(n, m,grid);

        // Space optimized          TC: O(M*N)
        //                          SC: O(N)
        return spaceOpt(n, m, grid);
    }
};

int main()
{

    return 0;
}