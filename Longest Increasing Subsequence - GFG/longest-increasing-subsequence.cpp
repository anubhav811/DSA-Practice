//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    int memo(int i , int prev, int a[] , int n,vector<vector<int>>&dp){
        
        if(i==n){
            return 0;
        }
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        
        int pick = (prev==-1 || a[i]>a[prev] ) ? 1 + memo(i+1,i,a,n,dp) : 0;
        int notPick = 0 + memo(i+1,prev,a,n,dp);
        
        return dp[i][prev+1] = max(pick,notPick);
    }
    int recur(int i , int prev, int a[] , int n){
        
        if(i<0){
            return 0;
        }
        int pick = (prev==-1 || a[i]>a[prev] ) ? 1 + recur(i+1,i,a,n) : 0;
        int notPick = 0 + recur(i+1,prev,a,n);
        
        return max(pick,notPick);
    }
    int longestSubsequence(int n, int a[])
    {
        // return recur(0,-1,a,n);
        
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return memo(0,-1,a,n,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends