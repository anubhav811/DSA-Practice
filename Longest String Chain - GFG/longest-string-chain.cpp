//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
      static bool cmp(string &a, string &b)
    {
        return a.length() < b.length();
    }
    

    // LCS APPROACH (Extra O(N^2))
    int lcs(string a, string b)
    {
        int n = a.size(), m = b.size();
        int dp[n+1][m+1];
        
        int i,j;
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max({dp[i-1][j],dp[i][j-1]});
            }
        }
        
        return dp[n][m];
    }

    // Compare function APPROACH 
    bool compare(string& s1, string& s2){
        if(s1.size() != s2.size() + 1) return false;
        
        int first = 0;
        int second = 0;
        
        while(first < s1.size()){
            if(second < s2.size() && s1[first] == s2[second]){
                first ++;
                second ++;
            }
            else first ++;
        }
        if(first == s1.size() && second == s2.size()) return true;
        else return false; 
    }

    int longestChain(int n, vector<string>& a) {
        // Code here
        
        int ans = 0;
        vector<int> dp(n,1);
        sort(a.begin(), a.end(), cmp);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(compare(a[i],a[j]) and dp[j]+1 >= dp[i])
                    dp[i] = max(dp[i], dp[j]+1);
            }
            
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends