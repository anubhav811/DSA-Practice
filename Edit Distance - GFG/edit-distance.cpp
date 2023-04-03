//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
        int recur(int i , int j,string s,string t){
            if(i<0){
                return j+1;
            }
            if(j<0){
                return i+1;
            }
            
            if(s[i]==t[j]){
                return 0 + recur(i-1,j-1,s,t);
            }
            int del = recur(i-1,j,s,t);
            int ins = recur(i-1,j-1,s,t);
            int rep = recur(i,j-1,s,t);
            
            return 1 + min(del,min(ins,rep));
            
        }
        int memo(int i , int j , string s , string t , vector<vector<int>> &dp){
            if(i<0) return j+1;
            if(j<0) return i+1;
            
            if(dp[i][j]!=-1) return dp[i][j];
            
            if(s[i]==t[j]) return 0 + memo(i-1,j-1,s,t,dp);
            
            int del = memo(i-1,j,s,t,dp);
            int ins = memo(i-1,j-1,s,t,dp);
            int rep = memo(i,j-1,s,t,dp);
            
            return dp[i][j] = 1 + min(del,min(ins,rep));
        }
        int editDistance(string s, string t) {
        // Code here
        
        int n = s.size();
        int m = t.size();
        

        // return recur(n-1,m-1,s,t);                  
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return memo(n-1,m-1,s,t,dp);
            
        
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends