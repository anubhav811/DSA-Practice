#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int tab(int x, int y, string str1, string str2, vector<vector<int>> &dp)
    {

        for (int i = 1; i < x + 1; i++)
        {
            for (int j = 1; j < y + 1; j++)
            {
                if (str1[i - 1] == str2[j - 1])
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
    string shortestCommonSupersequence(string str1, string str2)
    {
        int m = str1.size();
        int n = str2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        int lcs = tab(m, n, str1, str2, dp);

        string ans = "";

        int i = m;
        int j = n;

        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                ans += str1[i - 1];
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                ans += str1[i - 1];
                i--;
            }
            else
            {
                ans += str2[j - 1];
                j--;
            }
        }

        while (i > 0)
        {
            ans += str1[i - 1];
            i--;
        }
        while (j > 0)
        {
            ans += str2[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{

    return 0;
}