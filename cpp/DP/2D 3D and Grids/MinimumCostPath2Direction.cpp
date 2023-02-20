#include <bits/stdc++.h>
using namespace std;
int recur(int i, int j, vector<vector<int>> grid)
{

    if (i == 0 && j == 0)
        return grid[0][0];

    if (i < 0 || j < 0)
        return INT_MAX;
    ;

    int left = INT_MAX, up = INT_MAX;

    if (recur(i, j - 1, grid) != INT_MAX)
        left = grid[i][j] + recur(i, j - 1, grid);

    if (recur(i - 1, j, grid) != INT_MAX)
        up = grid[i][j] + recur(i - 1, j, grid);

    return min(up, left);
}
int minPathSum(vector<vector<int>> &grid)
{

    int n = grid.size();
    int m = grid[0].size();
    return recur(n - 1, m - 1, grid);
}

int main()
{

    return 0;
}