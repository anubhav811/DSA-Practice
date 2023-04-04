#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mod = 1e9+7;
    int recur(int i ,int j,string s,string t){

        if(i<0 && j>=0) return 0;
        else if(j<0) return 1;

        return (s[i]==t[j]) ? recur(i-1,j-1,s,t) + recur(i-1,j,s,t) : recur(i-1,j,s,t);
    }

    int memo(int i , int j , string s , string t,vector<vector<int>> &dp){

        if(dp[i][j]!=-1) return dp[i][j];
       
        if(i<0 && j>=0) return 0;
        else if(j<0) return 1;

        if(s[i]==t[j]){
            return dp[i][j] = recur(i-1,j-1,s,t) + recur(i-1,j,s,t);
        }
        return dp[i][j] =  recur(i-1,j,s,t);
    }

    int tab(int n , int m ,string s ,string t){

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=0;i<n+1;i++){
            dp[i][0] = 1;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = dp[i-1][j-1]%mod + dp[i-1][j]%mod;
                }
                else{
                    dp[i][j] = dp[i-1][j]%mod;
                }
            }
        }
        return dp[n][m];
    }

    int spaceOpt1(int n , int m ,string s ,string t){

        vector<int> prev(m+1,0) , curr(m+1,0);

        prev[0] = 1;

        curr = prev;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1]==t[j-1]){
                   curr[j] = prev[j-1]%mod + prev[j]%mod;
                }
                else{
                    curr[j] = prev[j]%mod;
                }
            }
            prev = curr;
        }
        return curr[m];
    }
    int spaceOpt2(int n , int m ,string s ,string t){

        vector<int> prev(m+1,0);

        prev[0] = 1;

        for(int i=1;i<n+1;i++){
            for(int j=m;j>=1;j--){
                if(s[i-1]==t[j-1]){
                   prev[j] = (prev[j-1] + prev[j])%mod;
                }
                else{
                    prev[j] = prev[j]%mod;
                }
            }
        }
        return prev[m];
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        // return recur(n-1,m-1,s,t);         TC : 2^m  + 2^n + O(N+M)(recursion auxillary stack)
 
        // vector<vector<int>> dp(n,vector<int>(m,-1));         TC : O(NxM)
                                                    //  /       SC : O(NxM) dp matrix + O(NXN) recursion auxillary stack
        // return memo(n-1,m-1,s,t,dp);

        // return tab(n,m,s,t);               // TC : O(NxM) Sc:O(NxM)dp matrix

        // return spaceOpt1(n,m,s,t) ;           // TC : O(NxM)  SC :O(M) + O(M);

        return spaceOpt2(n,m,s,t);            // TC : O(NxM)  SC :O(M) ;    
    }
};
int main()
{

    return 0;
}
