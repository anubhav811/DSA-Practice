#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int recur(vector<vector<int>> &points, int day, int last)
    {

        // base case
        if (day == 0)
        {
            int maxi = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    maxi = max(maxi, points[0][task]);
                }
            }
            return maxi;
        }

        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            int merit = 0;
            if (last != task)
            {
                merit = points[day][task] + recur(points, day - 1, task);
                maxi = max(maxi, merit);
            }
        }

        return maxi;
    }

    int memo(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
    {

        if (dp[day][last] != -1)
            return dp[day][last];

        if (day == 0)
        {
            int maxi = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                    maxi = max(maxi, points[0][task]);
            }
            return dp[day][last] = maxi;
        }

        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                int activity = points[day][task] + memo(day - 1, task, points, dp);
                maxi = max(maxi, activity);
            }
        }

        return dp[day][last] = maxi;
    }

    int tab(int n, vector<vector<int>> &points)
    {

        vector<vector<int>> dp(n, vector<int>(4, 0));

        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][1], points[0][0]);
        dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

        for (int day = 1; day < n; day++)
        {
            for (int last = 0; last < 4; last++)
            {
                dp[day][last] = 0;
                for (int task = 0; task < 3; task++)
                {
                    if (task != last)
                    {
                        int metric = points[day][task] + dp[day - 1][task];
                        dp[day][last] = max(metric, dp[day][last]);
                    }
                }
            }
        }
        return dp[n - 1][3];
    }
    int spaceOpt(int n, vector<vector<int>> &points)
    {
        vector<int> prev(4);

        prev[0] = max(points[0][1], points[0][2]);
        prev[1] = max(points[0][0], points[0][2]);
        prev[2] = max(points[0][1], points[0][0]);
        prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

        for (int day = 1; day < n; day++)
        {
            vector<int> temp(4, 0);
            for (int last = 0; last < 4; last++)
            {
                temp[last] = 0;
                for (int task = 0; task < 3; task++)
                {
                    if (task != last)
                    {
                        int merit = points[day][task] + prev[task];
                        temp[last] = max(temp[last], merit);
                    }
                }
            }
            prev = temp;
        }

        return prev[3];
    }

    int maximumPoints(vector<vector<int>> &points, int n)
    {
        // 1. Recursion
        // return recur(points,n-1,-1);

        // 2. Memoization          TC : O(N*4*3)
        //                         SC : O(N) + O(N*4)
        // vector<vector<int>> dp(n,vector<int>(4,-1));
        // return memo(n - 1, 3, points, dp);

        // 3. Tabulation           TC : O(N*4*3)
        //                         SC : O(N*4)
        // return tab(n, points);

        // 4. Space Optimized      TC : O(N*4*3)
        //                         SC : O(4)

        return spaceOpt(n, points);
    }
};

int main()
{

    return 0;
}