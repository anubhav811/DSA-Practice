#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1003;

class Solution{
public:
    int tab(int n , string &s){
        vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, 0)));
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=n-1;j++){
                // Base case 1;
                if(i>j) continue;
                
                for (int isTrue = 0; isTrue <= 1; isTrue++) {
                // Base case 2:
                if (i == j) {
                    if (isTrue == 1) dp[i][j][isTrue] = s[i] == 'T';
                    else dp[i][j][isTrue] = s[i] == 'F';
                    continue;
                }
                
                ll ways=0;
                for(int k=i+1;k<=j-1;k=k+2){
                    
                    ll lT = dp[i][k-1][1];
                    ll lF = dp[i][k-1][0]; 
                    ll rT = dp[k+1][j][1];
                    ll rF = dp[k+1][j][0];
                    
                    
                    if (s[k] == '&') {
                        if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
                        else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
                    }
                    else if (s[k] == '|') {
                        if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
                        else ways = (ways + (lF * rF) % mod) % mod;
                    }
                    else {
                        if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
                        else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
                    }

                }
        
                dp[i][j][isTrue] = ways%mod;
            }
        }
        
        }
        
        return dp[0][n-1][1];
    
    }
    int memo(int i,int j,string& s, int isTrue,vector<vector<vector<ll>>> &dp){
        
        if(i>j) return 0;
        if(i==j){
            if (isTrue == 1) return s[i] == 'T';
            else return s[i] == 'F';
        }
        
        if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        
        ll ways=0;
        for(int k=i+1;k<=j-1;k=k+2){
            
            ll lT = memo(i,k-1,s,1,dp);
            ll lF = memo(i,k-1,s,0,dp); 
            ll rT = memo(k+1,j,s,1,dp);
            ll rF = memo(k+1,j,s,0,dp);
            
            
            if (s[k] == '&') {
                if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
                else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
            }
            else if (s[k] == '|') {
                if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
                else ways = (ways + (lF * rF) % mod) % mod;
            }
            else {
                if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
                else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
            }

        }
        
        return dp[i][j][isTrue] = ways%mod;
    }
    int recur(int i,int j,string &s,int isTrue){
        
        if(i>j) return 0;
        if(i==j){
            if (isTrue == 1) return s[i] == 'T';
            else return s[i] == 'F';
        }
        
        ll ways=0;
        for(int k=i+1;k<=j-1;k=k+2){
            
            ll lt = recur(i,k-1,s,1);
            ll lf = recur(i,k-1,s,0); 
            ll rt = recur(k+1,j,s,1);
            ll rf = recur(k+1,j,s,0);
            
            
            if(s[k]=='&'){
                if(isTrue){
                    ways=  (ways+ (lt*rt)%mod)%mod;
                }
                else{
                    ways = (ways+ (lt*rf)%mod + (lf*rt)%mod + (lf*rf)%mod)%mod;
                }
            }
            else if(s[k]=='|'){
                if(isTrue){
                    ways=  (ways+ (lt*rf)%mod + (lf*rt)%mod + (lt*rt)%mod)%mod;
                }
                else{
                    ways = (ways + (lf*rf))%mod;
                }
            }
            
            else {
                if(isTrue){
                    ways = (ways + (lt*rf)%mod + (lf*rt)%mod )%mod;
                }
                else{
                    ways = (ways + (lf*rf)%mod + (lt*rt)%mod )%mod;
                }
            }
        }
        
        return ways;
    }
    int countWays(int N, string S){
        // code here
        
        // return recur(0,N-1,S,1);           // Exponential
        
        // vector<vector<vector<ll>>> dp(N, vector<vector<ll>>(N, vector<ll>(2, -1)));
        // return memo(0,N-1,S,1,dp); // TC :  O(N*N*2 * N) ~ O(N^3) There are a total of 2*N^2 no. 
                                      // of states. And for each state, we are running a 
                                      // partitioning loop roughly for N times.
                                      
                                      // SC : O(2*N^2) + Auxiliary stack space of O(N), 2*N^2 for the dp array we are using.
    
        return tab(N,S); //TC :  O(N*N*2 * N) ~ O(N^3) There are a total of 2*N2 no. of states. 
                        // And for each state, we are running a partitioning loop \
                        // roughly for N times.
                        
                        //SC : O(2*N^2)  
    }
    
    
};
