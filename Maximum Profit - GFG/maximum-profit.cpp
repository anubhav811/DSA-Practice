//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     
    int spaceOpt(int n , int k,int prices[]){
        vector<vector<int>> next(2,vector<int>(k+1,0)), curr(2,vector<int>(k+1,0));

        for(int i = n-1; i>=0;i--){
            for(int j=0 ; j<=2;j++){
                for(int t = 1;t<=k;t++){
                    if(j==0){
                            curr[j][t] = max(next[0][t],-prices[i]+next[1][t]);
                        }
                    if(j==1){
                            curr[j][t] = max(next[1][t], prices[i]+next[0][t-1]);
                    }
                }
                next = curr;
            }
        }
        return curr[0][k];
    }
    int tab(int n , int k,int prices[]){
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int t=1;t<=k;t++){
                    if(j==0){
                        dp[i][j][t] = max(dp[i+1][0][t],-prices[i]+dp[i+1][1][t]);
                    }
                    if(j==1){
                        dp[i][j][t] = max(dp[i+1][1][t], prices[i]+dp[i+1][0][t-1]);
                    }
                }
            }
        }

        return dp[0][0][k];

    }
    int memo(int i , int buy , int trxn ,int n, int prices[],vector<vector<vector<int>>> &dp){
    
        // Base Case
        if(i==n || trxn==0) return 0;
        
        if(dp[i][buy][trxn] != -1){
            return dp[i][buy][trxn];
        }
        
        int profit ;
        if(buy==0) 
            profit = max(memo(i+1,0,trxn,n,prices,dp) , -prices[i] + memo(i+1,1,trxn,n,prices,dp));
        if(buy==1) 
            profit = max(memo(i+1,1,trxn,n,prices,dp) , prices[i] + memo(i+1,0,trxn-1,n,prices,dp));
            
        return dp[i][buy][trxn] = profit;

    }
    
    int recur(int i , int buy , int trxn, int n, int prices[]){

        if(i==n || trxn==0) return 0;

        int profit ;
        if(buy==0) 
            profit = max(recur(i+1,0,trxn,n,prices) , -prices[i] + recur(i+1,1,trxn,n,prices));
        if(buy==1) 
            profit = max(recur(i+1,1,trxn,n,prices) , prices[i] + recur(i+1,0,trxn-1,n,prices));
        
        return profit;
    }
    int maxProfit(int K, int N, int prices[]) {
        // code here
        
        // return recur(0,0,K,N,prices);    // TC : Exponential     SC : O(N*2*K) +  O(N)

        // vector<vector<vector<int>>> dp(N,vector<vector<int>>(2,vector<int>(k+1,-1)));
        // return memo(0,0,K,N,prices,dp);   // TC :  O(N*2*K)      SC : O(N*2*K) +  O(N)
 
        // return tab(N,K,prices);           // TC : O(N*2*K)       SC : O(N*2*K)
 
        return spaceOpt(N,K,prices);          // TC : O(N*2*K)       SC : O(2*K) ~ O(K)
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends