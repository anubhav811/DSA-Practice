#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int spaceOpt(int n, string s1, string s2)
    {

        vector<int> prev(n + 1), curr(n + 1);

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    curr[j] = 1 + prev[j - 1];
                }
                else
                {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }
        return curr[n];
    }
    int tab(int n, string s1, string s2)
    {

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
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

        return dp[n][n];
    }

    int minInsertions(string s)
    {

        string t = s;
        reverse(t.begin(), t.end());
        int n = s.size();
        int l = spaceOpt(n, s, t);
        return abs(l - n);
    }
};
int main()
{

    return 0;
}