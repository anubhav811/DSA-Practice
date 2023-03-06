/**
 * We have two conditions:

if(S1[i-1] != S2[j-1]), the characters don’t match, therefore the consecutiveness of characters is broken. So we set the cell value (dp[i][j]) as 0.
if(S1[i-1] == S2[j-1]), then the characters match and we simply set its value to 1+dp[i-1][j-1]. We have done so because dp[i-1][j-1] gives us the longest common substring till the last cell character (current strings -{matching character}). As the current cell’s character is matching we are adding 1 to the consecutive chain.
Note: dp[n][m] will not give us the answer; rather the maximum value in the entire dp array will give us the length of the longest common substring. This is because there is no restriction that the longest common substring is present at the end of both the strings.

 *
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lcsSpaceOpt(string s1, string s2, int n, int m)
    {

        vector<int> prev(m + 1, 0), cur(m + 1, 0);

        int ans = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    int val = 1 + prev[j - 1];
                    cur[j] = val;
                    ans = max(ans, val);
                }
                else
                    cur[j] = 0;
            }
            prev = cur;
        }

        return ans;
    }
    int lcsTab(string s1, string s2, int n, int m)
    {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        int mx = 0;
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    mx = max(mx, dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }

        return mx;
    }
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {

        // return lcsTab(S1,S2,n,m);       O(N*M)
        //                                          O(N*M)

        return lcsSpaceOpt(S1, S2, n, m); // O(N*M)
                                          // O(M)
    }
};

int main()
{

    return 0;
}