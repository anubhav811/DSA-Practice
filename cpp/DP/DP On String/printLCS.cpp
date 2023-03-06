#include <bits/stdc++.h>
using namespace std;
int tab(int x, int y, string s1, string s2, vector<vector<int>> &dp)
{
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
int main()
{
    string s = "abcde";
    string t = "bdgek";

    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
    int len = tab(s.size(), t.size(), s, t, dp);
    string ans = "";

    int i = s.size();
    int j = t.size();

    while (i > 0 && j > 0)
    {

        if (s[i - 1] == t[j - 1])
        {
            ans.push_back(s[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}