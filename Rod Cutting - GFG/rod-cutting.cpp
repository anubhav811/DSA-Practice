//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int spaceOpt(int n,int price[]){
        vector<int> prev(n+1,0),curr(n+1,0);
        
        for(int j=0;j<=n;j++){
            curr[j] = (j/1) * price[0];
        }
        
        prev = curr;
        
         for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                
                int notTake = 0 + prev[j];
                int rodlen = i+1;
                int take = (rodlen<=j) ? price[i] + curr[j-rodlen] : INT_MIN;
                
                curr[j] = max(notTake,take);
            }
            prev = curr;
        }
        
        return prev[n];
        
    }
    int tab(int n,int price[]){
        vector<vector<int>> dp(n,vector<int>(n+1,0));
        for(int j=0;j<=n;j++){
            dp[0][j] = (j/1) * price[0];
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                
                int notTake = 0 + dp[i-1][j];
                int rodlen = i+1;
                int take = (rodlen<=j) ? price[i] + dp[i][j-rodlen] : INT_MIN;
                
                dp[i][j] = max(notTake,take);
            }
        }
        
        return dp[n-1][n];
    }
    int memo(int i,int price[],int n,vector<vector<int>> &dp){
        if(i==0){
            return (n/(i+1))*price[i];
        }
        if(dp[i][n]!=-1)
            return dp[i][n];
        int notTake = 0 + memo(i-1,price,n,dp);
        int rodlen = i+1;
        int take = (rodlen<=n) ? price[i] + memo(i,price,n-rodlen,dp) : INT_MIN; 
        return dp[i][n]=max(take,notTake);
    }
    int recur(int i , int price[], int n){
        
        if(i==0){
            return (n/(i+1))*price[i];
        }
        
        int notTake = 0 + recur(i-1,price,n);
        int rodlen = i+1;
        int take = (rodlen<=n) ? price[i] + recur(i,price,n-rodlen) : INT_MIN; 
        return max(take,notTake);
    }
    int cutRod(int price[], int n) {
        //code here
        // return recur(n-1,price,n);
        
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // return memo(n-1,price,n,dp);
        
        // return tab(n,price);
        
        return spaceOpt(n,price);
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends