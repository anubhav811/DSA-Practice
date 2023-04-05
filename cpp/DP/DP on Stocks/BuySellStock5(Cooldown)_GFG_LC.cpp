#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int spaceOpt(int n ,vector<int> & prices){
        vector<vector<int>> curr(2,vector<int>(2,0)),next(2,vector<int>(2,0));

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int t=0;t<=1;t++){
                    if(j==0){
                        if(t==1){
                            curr[j][t] = next[0][0];
                        }
                        else{
                            curr[j][t] = max(next[0][0], -prices[i] + next[1][1]);
                        }  
                    }
                    if(j==1){
                            curr[j][t] = max(next[1][0] , prices[i] + next[0][1]);
                    }   
                }
            }
            next=curr;
        }

        return curr[0][0];
    }
    int tab(int n ,vector<int>& prices){
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(2,0)));

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int t=0;t<=1;t++){
                    if(j==0){
                        if(t==1){
                            dp[i][j][t] = dp[i+1][0][0];
                        }
                        else{
                            dp[i][j][t] = max(dp[i+1][0][0], -prices[i] + dp[i+1][1][1]);
                        }  
                    }
                    if(j==1){
                            dp[i][j][t] = max(dp[i+1][1][0] , prices[i] + dp[i+1][0][1]);
                    }   
                }
            }
        }

        return dp[0][0][0];

    }
    int memo(int i , int buy , int cooldown , vector<int>& prices,vector<vector<vector<int>>> &dp){
            
        if(i==prices.size()) return 0;

        if(dp[i][buy][cooldown] != -1) return dp[i][buy][cooldown];
        int profit ;
        if(buy==0){
            if(cooldown){
                profit = memo(i+1,0,0,prices,dp);
            }
            else{
                profit = max(memo(i+1,0,0,prices,dp) , -prices[i] + memo(i+1,1,1,prices,dp));
            }
        } 
        if(buy==1){
    
            profit = max(memo(i+1,1,0,prices,dp) , prices[i] + memo(i+1,0,1,prices,dp));
            
        }   
        
        return dp[i][buy][cooldown] = profit;

    }
    
    int recur(int i , int buy , int cooldown, vector<int> &prices){

        if(i==prices.size()) return 0;
        int profit ;
        if(buy==0){
            if(cooldown){
                profit = recur(i+1,0,0,prices);
            }
            else{
                profit = max(recur(i+1,0,0,prices) , -prices[i] + recur(i+1,1,1,prices));
            }
        } 
        if(buy==1){
    
            profit = max(recur(i+1,1,0,prices) , prices[i] + recur(i+1,0,1,prices));
            
        }   
        
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // return recur(0,0,0,prices);    // TC : Exponential     SC : O(N*2*2) +  O(N)

        // vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        // return memo(0,0,0,prices,dp);   // TC :  O(N*2*2)      SC : O(N*2*2) +  O(N)
 
        // return tab(n,prices);           // TC : O(N*2*2)       SC : O(N*2*2)
 
        return spaceOpt(n,prices);          // TC : O(N*2*2)       SC : O(2*2) ~ O(K)
    }
};
int main()
{

    return 0;
}