#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int pqMethod(vector<vector<int>> grid)
    {

        int n = grid.size();
        int m = grid[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({grid[0][0], {0, 0}});

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while (!pq.empty())
        {
            int cost = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;

            pq.pop();

            for (int i = 0; i < 4; i++)
            {
                int row = r + delrow[i];
                int col = c + delcol[i];

                if (row >= 0 && row < n && col >= 0 && col < m && grid[row][col] + cost < dist[row][col])
                {
                    dist[row][col] = grid[row][col] + cost;

                    if (row == n - 1 && col == m - 1)
                        return dist[row][col];

                    pq.push({dist[row][col], {row, col}});
                }
            }
        }
    }

    int recur(int i, int j, vector<vector<int>> grid, vector<vector<int>> &vis)
    {

        // base
        if (i == 0 && j == 0)
            return grid[0][0];

        int left, right, down, up;

        if (j - 1 >= 0 && vis[i][j - 1] == 0)
        {
            vis[i][j] = 1;
            left = grid[i][j] + recur(i, j - 1, grid, vis);
            vis[i][j] = 0;
        }
        if (j + 1 < grid.size() && vis[i][j + 1] == 0)
        {
            vis[i][j] = 1;
            right = grid[i][j] + recur(i, j + 1, grid, vis);
            vis[i][j] = 0;
        }
        if (i + 1 < grid.size() && vis[i + 1][j] == 0)
        {
            vis[i][j] = 1;
            down = grid[i][j] + recur(i + 1, j, grid, vis);
            vis[i][j] = 0;
        }
        if (i - 1 >= 0 && vis[i - 1][j] == 0)
        {
            vis[i][j] = 1;
            up = grid[i][j] + recur(i - 1, j, grid, vis);
            vis[i][j] = 0;
        }

        return min(left, min(right, min(down, up)));
    }

    int minimumCostPath(vector<vector<int>> &grid)
    {
        // 1. Recursion
        // int n = grid.size();
        // int m = grid[0].size();

        // vector<vector<int>> vis(n,vector<int>(m,0));

        // return recur(n-1,m-1,grid,vis);

        return pqMethod(grid);
    }
};

int main()
{

    return 0;
}