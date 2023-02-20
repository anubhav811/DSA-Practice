#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int recur(int i, int j, vector<vector<int>> grid)
    {
        if (j < 0 || j >= grid.size())
            return 1e9;

        if (i == 0)
            return grid[0][j];

        int up = grid[i][j] + recur(i - 1, j, grid);
        int upL = grid[i][j] + recur(i - 1, j - 1, grid);
        int upR = grid[i][j] + recur(i - 1, j + 1, grid);

        return min(up, min(upL, upR));
    }

    int memo(int i, int j, vector<vector<int>> grid, vector<vector<int>> dp)
    {

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (j < 0 || j >= grid.size())
            return 1e9;

        if (i == 0)
            return grid[0][j];

        int up = grid[i][j] + memo(i - 1, j, grid, dp);
        int upL = grid[i][j] + memo(i - 1, j - 1, grid, dp);
        int upR = grid[i][j] + memo(i - 1, j + 1, grid, dp);

        return dp[i][j] = min(up, min(upL, upR));
    }

    int tab(vector<vector<int>> grid)
    {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Initializing first row - base condition
        for (int j = 0; j < m; j++)
        {
            dp[0][j] = grid[0][j];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                int up = grid[i][j] + dp[i - 1][j];

                int leftDiagonal = grid[i][j];
                if (j - 1 >= 0)
                    leftDiagonal += dp[i - 1][j - 1];
                else
                    leftDiagonal += 1e9;

                int rightDiagonal = grid[i][j];
                if (j + 1 < m)
                    rightDiagonal += dp[i - 1][j + 1];
                else
                    rightDiagonal += 1e9;

                dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
            }
        }

        int mini = INT_MAX;

        for (int j = 0; j < m; j++)
        {
            mini = min(mini, dp[n - 1][j]);
        }

        return mini;
    }

    int spaceOpt(vector<vector<int>> grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> prev(n);
        vector<int> curr(n);
        // Initializing first row - base condition
        for (int j = 0; j < m; j++)
        {
            prev[j] = grid[0][j];
        }

        for (int i = 1; i < n; i++)
        {
            vector<int> temp(n);
            for (int j = 0; j < m; j++)
            {

                int up = grid[i][j] + prev[j];

                int leftDiagonal = grid[i][j];
                if (j - 1 >= 0)
                    leftDiagonal += prev[j - 1];
                else
                    leftDiagonal += 1e9;

                int rightDiagonal = grid[i][j];
                if (j + 1 < m)
                    rightDiagonal += prev[j + 1];
                else
                    rightDiagonal += 1e9;

                curr[j] = min(up, min(leftDiagonal, rightDiagonal));
            }
            prev = curr;
        }

        int mini = INT_MAX;

        for (int j = 0; j < m; j++)
        {
            mini = min(mini, prev[j]);
        }

        return mini;
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {

        // int mini = INT_MAX;
        // for(int j=0;j<Matrix.size();j++)
        //   mini = min(mini,recur(n-1,j,matrix));
        // return mini;

        // vector<vector<int>> dp(n,vector<int>(n,-1));    TC: O(N*M) SC: O(N) + O(N*M)
        // int mini = INT_MAX;
        // for(int j=0;j<Matrix.size();j++)
        //   mini = min(mini,memo(n-1,j,matrix,dp));
        // return mini;

        // return tab(matrix);                              TC:O(N*M)  SC: O(N*M)O(M)

        return spaceOpt(matrix); //                         TC:O(N*M)  SC: O(M)
    }
};
int main()
{

    return 0;
}