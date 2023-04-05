//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
     long long spaceOpt(int n , vector<long long> &A){
        vector<long long> next(2,-1) , curr(2,-1);

        next[0] = 0;
        next[1] = 0;

        for(int i=n-1;i>=0;i--){            
            for(int buy=0;buy<2;buy++){
                if(buy==0)
                    curr[0] = max(0 + next[0],-A[i] + next[1]);
                if(buy==1)
                    curr[1] = max(0 + next[1],A[i] + next[0]);
            }
            next = curr;
        }

        return curr[0];
    }
    long long tab(int n ,vector<long long> &A)
    {
        vector<vector<long long>> dp(n+1,vector<long long>(2,-1));

        dp[n][0] = 0 ;
        dp[n][1] = 0;

        for(int i=n-1;i>=0;i--){            
            for(int buy=0;buy<2;buy++){
                if(buy==0)
                    dp[i][0] = max(0 + dp[i+1][0],-A[i] + dp[i+1][1]);
                if(buy==1)
                    dp[i][1] = max(0 + dp[i+1][1],A[i] + dp[i+1][0]);
            }
        }

        return dp[0][0];
    }
    long long memo(int i , int buy , vector<long long> &A, vector<vector<long long>> &dp){
        if(i==A.size()) return 0; 

        if(dp[i][buy]!=-1)  return dp[i][buy];
        long profit;

        if(buy==0){
            profit = max(0+memo(i+1,0,A,dp), -A[i] + memo(i+1,1,A,dp));
        }

        if(buy==1){
            profit = max(0+memo(i+1,1,A,dp), A[i] + memo(i+1,0,A,dp));
        }

        return dp[i][buy]=profit;
    }
    long long recur(int i ,int buy , vector<long long> &A){
        
        if(i==A.size()) return 0; 

        long profit;

        if(buy==0){
            profit = max(0+recur(i+1,0,A), -A[i] + recur(i+1,1,A));
        }

        if(buy==1){
            profit = max(0+recur(i+1,1,A), A[i] + recur(i+1,0,A));
        }

        return profit;
    }
    long long maximumProfit(vector<long long>&A, int n) {

        // return recur(0,0,A);                                 TC : 2^n  SC : O(n)
        // vector<vector<long long>> dp(n,vector<long long>(2,-1));  TC : O(N*2) SC :  O(N*2) + O(N)

        // return memo(0,0,A,dp);

        // return tab(n,A);                               TC : O(N*2) SC :  O(N*2) 

        return spaceOpt(n,A);                             //TC : O(N*2) SC : O(N)

    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends