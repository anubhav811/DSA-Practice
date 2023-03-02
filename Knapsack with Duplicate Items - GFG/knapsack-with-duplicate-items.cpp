//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int recur(int i,int W, int val[],int wt[]){
        if(i==0){
            return ((int)(W/wt[0]))*val[0];
        }
        
        int take = (wt[i]<=W) ? val[i] + recur(i,W-wt[i],val,wt):INT_MIN;
        int nottake = recur(i-1,W,val,wt);
        
        return max(take,nottake);
    }
    int memo(int i,int W, int val[],int wt[],vector<vector<int>> &dp){
        
        if(dp[i][W]!=-1)
            return dp[i][W];
        if(i==0){
            return ((int)(W/wt[0]))*val[0];
        }
        
        int take = (wt[i]<=W) ? val[i] + memo(i,W-wt[i],val,wt,dp):INT_MIN;
        int nottake = memo(i-1,W,val,wt,dp);
        
        return dp[i][W] = max(take,nottake);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // Recursion                TLE   TC: Exp
        //                                SC: O(W)
        // return recur(N-1,W,val,wt);
        
        // Memoization                    TC: O(N*W)
        vector<vector<int>> dp(N,vector<int>(W+1,-1));
        return memo(N-1,W,val,wt,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends