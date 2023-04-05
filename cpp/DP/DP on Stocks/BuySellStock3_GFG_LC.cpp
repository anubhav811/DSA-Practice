#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
        int spaceOpt(int n , vector<int> & prices){
            vector<vector<int>> next(2,vector<int>(3,0)), curr(2,vector<int>(3,0));

            for(int i = n-1; i>=0;i--){
                for(int j=0 ; j<=2;j++){
                    for(int k = 1;k<=2;k++){
                        if(j==0){
                                curr[j][k] = max(next[0][k],-prices[i]+next[1][k]);
                            }
                        if(j==1){
                                curr[j][k] = max(next[1][k], prices[i]+next[0][k-1]);
                        }
                    }
                    next = curr;
                }
            }
            return curr[0][2];
        }
        int tab(int n , vector<int>& prices){
            vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

            for(int i=n-1;i>=0;i--){
                for(int j=0;j<2;j++){
                    for(int k=1;k<=2;k++){
                        if(j==0){
                            dp[i][j][k] = max(dp[i+1][0][k],-prices[i]+dp[i+1][1][k]);
                        }
                        if(j==1){
                            dp[i][j][k] = max(dp[i+1][1][k], prices[i]+dp[i+1][0][k-1]);
                        }
                    }
                }
            }

            return dp[0][0][2];

        }
        int memo(int i , int buy , int trxn , vector<int>& prices,vector<vector<vector<int>>> &dp){
        
            // Base Case
            if(i==prices.size() || trxn==0) return 0;
            
            if(dp[i][buy][trxn] != -1){
                return dp[i][buy][trxn];
            }
            
            int profit ;
            if(buy==0) 
                profit = max(memo(i+1,0,trxn,prices,dp) , -prices[i] + memo(i+1,1,trxn,prices,dp));
            if(buy==1) 
                profit = max(memo(i+1,1,trxn,prices,dp) , prices[i] + memo(i+1,0,trxn-1,prices,dp));
                
            return dp[i][buy][trxn] = profit;

        }
        
        int recur(int i , int buy , int trxn, vector<int> &prices){

            if(i==prices.size() || trxn==0) return 0;

            int profit ;
            if(buy==0) 
                profit = max(recur(i+1,0,trxn,prices) , -prices[i] + recur(i+1,1,trxn,prices));
            if(buy==1) 
                profit = max(recur(i+1,1,trxn,prices) , prices[i] + recur(i+1,0,trxn-1,prices));
            
            return profit;
        }
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        // return recur(0,0,2,prices);    // TC : Exponential     SC : O(N*2*3) +  O(N)

        // vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        // return memo(0,0,2,prices,dp);   // TC :  O(N*2*3)      SC : O(N*2*3) +  O(N)
 
        // return tab(n,prices);           // TC : O(N*2*3)       SC : O(N*2*3)
 
        return spaceOpt(n,prices);          // TC : O(N*2*3)       SC : O(2*3) ~ O(1)
    }
};
int main()
{

    return 0;
}