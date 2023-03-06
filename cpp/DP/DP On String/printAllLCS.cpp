
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> all_longest_common_subsequences(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        vector<vector<unordered_set<string>>> res(n + 1, vector<unordered_set<string>>(m + 1));

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < m + 1; j++)
            {
                if (i == 0 || j == 0)
                {
                    res[i][j].insert("");
                }
            }
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    for (auto it : res[i - 1][j - 1])
                        res[i][j].insert(it + s[i - 1]);
                }

                if (dp[i][j] == dp[i - 1][j])
                {
                    for (auto it : res[i - 1][j])
                        res[i][j].insert(it);
                }

                if (dp[i][j] == dp[i][j - 1])
                {
                    for (auto it : res[i][j - 1])
                        res[i][j].insert(it);
                }
            }
        }

        vector<string> v1;

        for (auto it : res[n][m])
        {
            if (it != "")
                v1.push_back(it);
        }
        sort(v1.begin(), v1.end());

        return v1;
    }
};
int main()
{
    return 0;
}
