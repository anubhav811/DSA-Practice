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
            int ins = recur(i,j-1,s,t);
            int del = recur(i-1,j,s,t);
            int rep = recur(i-1,j-1,s,t);
            
            return 1 + min(del,min(ins,rep));
            
        }
        int memo(int i , int j , string &s , string &t , vector<vector<int>> &dp){
            if(i<0) return j+1;
            if(j<0) return i+1;
            
            if(dp[i][j]!=-1) return dp[i][j];
            
            if(s[i]==t[j]) return 0 + memo(i-1,j-1,s,t,dp);
            
            int ins = memo(i,j-1,s,t,dp);
            int del = memo(i-1,j,s,t,dp);
            int rep = memo(i-1,j-1,s,t,dp);
            
            return dp[i][j] = 1 + min(del,min(ins,rep));
        }
        
        int tab(int n , int m ,string &s ,string &t){
            
            vector<vector<int>> dp(n+1,vector<int>(m+1,0));
            
            for(int i=0;i<n+1;i++){
                dp[i][0] = i;
            }
            
            for(int j=0;j<m+1;j++){
                dp[0][j] = j;
            }
            
            
            for(int i = 1; i<n+1;i++){
                for(int j=1; j<m+1;j++){
                    
                    if(s[i-1]==t[j-1]){
                        dp[i][j] = 0 + dp[i-1][j-1];
                    }
                    else{
                        int ins = dp[i][j-1];
                        int del = dp[i-1][j];
                        int rep = dp[i-1][j-1];
                        
                        dp[i][j] = 1 + min(del,min(ins,rep));
                    }
                }
            }
            
            return dp[n][m];
        }
        int editDistance(string s, string t) {
        // Code here
        
        int n = s.size();
        int m = t.size();
        
 
        // return recur(n-1,m-1,s,t);                   TC  : Exponential SC: auxiallary stacck O(n*m)
         
        // vector<vector<int>> dp(n,vector<int>(m,-1));  TC : O(N*M) SC : O(N*M) + O(N*M)(stack)
        // return memo(n-1,m-1,s,t,dp);
            
        return tab(n,m,s,t);                 //  TC : O(N*M) SC : O(N*M) 
        
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