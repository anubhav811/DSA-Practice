//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    
    int recur(int i , int j){
        if(i==0 && j==0) return 1;
        
        if(i<0 || j<0) return 0;
        
        int up = recur(i-1,j);
        int left = recur(i,j-1);
        
        return up+left;
    }
    
    int memo(int i,int j,vector<vector<int>> &dp){
        
          if(i==0 && j == 0)
            return 1;
          
          if(i<0 || j<0)
            return 0;
          
          if(dp[i][j]!=-1) 
            return dp[i][j];
            
          int up = memo(i-1,j,dp);
          int left = memo(i,j-1,dp);
          
          return dp[i][j] = up+left;

    }
    int NumberOfPath(int a, int b)
    {
        // Recursion TLE  TC = O(2^(m*n))
        //                SC = path length m-1+n-1
        // return recur(a-1,b-1);    
        
        // Memo
        vector<vector<int>> dp(a,vector<int>(b,-1));
        return memo(a-1,b-1,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends