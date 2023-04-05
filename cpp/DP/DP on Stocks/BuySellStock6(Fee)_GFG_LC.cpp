#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int spaceOpt(int n , vector<int> &A,int fee){
        vector<int> next(2,-1) , curr(2,-1);

        next[0] = 0;
        next[1] = 0;

        for(int i=n-1;i>=0;i--){            
            for(int buy=0;buy<2;buy++){
                if(buy==0)
                    curr[0] = max(0 + next[0],-A[i] + next[1]);
                if(buy==1)
                    curr[1] = max(0 + next[1],A[i] + next[0] -fee);
            }
            next = curr;
        }

        return curr[0];
    }
    int tab(int n ,vector<int> &A,int fee)
    {
        vector<vector<int>> dp(n+1,vector<int>(2,-1));

        dp[n][0] = 0 ;
        dp[n][1] = 0;

        for(int i=n-1;i>=0;i--){            
            for(int buy=0;buy<2;buy++){
                if(buy==0)
                    dp[i][0] = max(0 + dp[i+1][0],-A[i] + dp[i+1][1]);
                if(buy==1)
                    dp[i][1] = max(0 + dp[i+1][1],A[i] + dp[i+1][0]-fee);
            }
        }

        return dp[0][0];
    }
    int memo(int i , int buy , vector<int> &A, int fee,vector<vector<int>> &dp){
        if(i==A.size()) return 0; 

        if(dp[i][buy]!=-1)  return dp[i][buy];
        long profit;

        if(buy==0){
            profit = max(0+memo(i+1,0,A,fee,dp), -A[i] + memo(i+1,1,A,fee,dp));
        }

        if(buy==1){
            profit = max(0+memo(i+1,1,A,fee,dp), A[i] + memo(i+1,0,A,fee,dp) -fee);
        }

        return dp[i][buy]=profit;
    }
    int recur(int i ,int buy , vector<int> &A,int fee){
        
        if(i==A.size()) return 0; 

        long profit;

        if(buy==0){
            profit = max(0+recur(i+1,0,A,fee), -A[i] + recur(i+1,1,A,fee));
        }

        if(buy==1){
            profit = max(0+recur(i+1,1,A,fee), A[i] + recur(i+1,0,A,fee) - fee);
        }

        return profit;
    }
    int maxProfit(vector<int>& A, int fee) {

        int n = A.size();
        // return recur(0,0,A,fee);                                  // TC : 2^n  SC : O(n)
        // vector<vector<long long>> dp(n,vector<long long>(2,-1));  // TC : O(N*2) 
        //                                                              SC :  O (N*2) + O(N)
        // return memo(0,0,A,fee,dp);

        // return tab(n,A,fee);                                         // TC : O(N*2) 
        //                                                                 SC :  O(N*2) 

        return spaceOpt(n,A,fee);                             //TC : O(N*2) SC : O(N)
        
    }
};
int main()
{

    return 0;
}