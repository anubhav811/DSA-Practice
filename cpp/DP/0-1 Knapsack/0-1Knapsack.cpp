/*
You are given weights and values of N items, put these items in a knapsack of capacity W to get
the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and
weights associated with N items respectively. Also given an integer W which represents knapsack capacity,
find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W.
You cannot break an item, either pick the complete item or dont pick it (0-1 property).
*/

#include <bits/stdc++.h>
using namespace std;
int knapSackRecursive(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] <= W)
    {
        return max(val[n - 1] + knapSackRecursive(W - wt[n - 1], wt, val, n - 1), knapSackRecursive(W, wt, val, n - 1));
    }
    else if (wt[n - 1] > W)
    {
        return knapSackRecursive(W, wt, val, n - 1);
    }

    return 0;
}

int knapsackMemoization(int w, int wt[], int val[], int n, vector<vector<int>> &t)
{
    if (n == 0 || w == 0)
    {
        return 0;
    }

    if (t[n][w] != -1)
        return t[n][w];

    if (wt[n - 1] <= w)
    {
        return t[n][w] = max(val[n - 1] + knapsackMemoization(w - wt[n - 1], wt, val, n - 1, t), knapsackMemoization(w, wt, val, n - 1, t));
    }
    else if (wt[n - 1] > w)
    {
        return t[n][w] = knapsackMemoization(w, wt, val, n - 1, t);
    }

    return 0;
}

int knapsackDP(int w, int wt[], int val[], int n)
{
    vector<vector<int>> t(n + 1, vector<int>(w + 1, -1));
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < w + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
            }
            else if (wt[i - 1] > j)
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][w];
}

int main()
{
    int n = 3;
    int w = 4;
    int val[n] = {1, 2, 3};
    int wt[n] = {4, 5, 1};

    // cout << knapSackRecursive(w, wt, val, n) << endl;

    // vector<vector<int>> t(n + 1, vector<int>(w + 1, -1));
    // cout << knapsackMemoization(w, wt, val, n, t) << endl;

    cout << knapsackDP(w, wt, val, n) << endl;
    return 0;
}