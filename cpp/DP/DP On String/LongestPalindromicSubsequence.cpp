#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int spaceOpt(int x, int y, string s1, string s2)
    {

        vector<int> prev(y + 1, 0), curr(y + 1, 0);

        for (int i = 1; i < x + 1; i++)
        {
            for (int j = 1; j < y + 1; j++)
            {

                if (s1[i - 1] == s2[j - 1])
                {
                    curr[j] = 1 + prev[j - 1];
                }
                else
                {
                    curr[j] = max(curr[j - 1], prev[j]);
                }
            }
            prev = curr;
        }

        return prev[y];
    }
    int tab(int x, int y, string s1, string s2)
    {

        // Adding one extra to shift indices to one right
        vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));

        for (int i = 1; i < x + 1; i++)
        {
            for (int j = 1; j < y + 1; j++)
            {
                // as we have shifted right once , we will have to do 1 minus index to fetch the char from string
                // because string ke indexes thori shift kare the , kar bhi nahi skte lmao
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[x][y];
    }
    int memo(int i1, int i2, string s1, string s2, vector<vector<int>> &dp)
    {

        if (i1 < 0 || i2 < 0)
        {
            return 0;
        }

        if (dp[i1][i2] != -1)
        {
            return dp[i1][i2];
        }

        if (s1[i1] == s2[i2])
            return 1 + memo(i1 - 1, i2 - 1, s1, s2, dp);
        else
        {
            return max(memo(i1 - 1, i2, s1, s2, dp), memo(i1, i2 - 1, s1, s2, dp));
        }
    }
    int recur(int i1, int i2, string s1, string s2)
    {
        if (i1 < 0 || i2 < 0)
        {
            return 0;
        }

        if (s1[i1] == s2[i2])
            return 1 + recur(i1 - 1, i2 - 1, s1, s2);
        else
        {
            return max(recur(i1 - 1, i2, s1, s2), recur(i1, i2 - 1, s1, s2));
        }
    }
    int longestPalindromeSubseq(string s)
    {

        string t = s;
        reverse(t.begin(), t.end());

        int x = s.size();
        int y = t.size();
        // Recursion
        // return recur(x-1,y-1,s,t);                       // TC : O(2^x *  2^y)
        // SC : O(X+Y)

        // Memoization
        // vector<vector<int>> dp(x,vector<int>(y,-1));         // TC : O(X *  Y)
        // SC : O(X*Y) + O(X+Y)
        // return memo(x-1,y-1,s,t,dp);

        // Tabulation                                       TC : O(X*Y)
        //                                                  SC : O(X*Y)
        // return tab(x,y,s,t);

        // Space Optimization                               TC : O(X*Y)
        //                                                  SC : O(X+1)
        return spaceOpt(x, y, s, t);
    }
};
int main()
{

    return 0;
}