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
        return curr[y];
    }

    int tab(int x, int y, string str1, string str2)
    {
        vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));
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
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        int l = spaceOpt(n, m, word1, word2);
        int deletionsFromWord1 = n - l;
        int deletionsFromWord2 = m - l; //  This is actually exactly the same thing as Insertion in word2 as it is implied in the GFG version of this question.
        return deletionsFromWord1 + deletionsFromWord2;
    }
};
int main()
{

    return 0;
}