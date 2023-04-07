//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int memo(int i , int j , int arr[],vector<vector<int>> &dp){
        if(i==j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int mini = 1e9;
        
        int steps = 0;
        for(int k=i;k<=j-1;k++){
            steps = arr[i-1]*arr[k]*arr[j] + memo(i,k,arr,dp) + memo(k+1,j,arr,dp);
            mini = min(mini,steps);
        }
        
        return dp[i][j] = mini;
    }
    int recur(int i,int j, int arr[]){
        if(i==j) return 0;
        
        int mini = 1e9;
        
        int steps = 0;
        for(int k=i;k<=j-1;k++){
            steps = arr[i-1]*arr[k]*arr[j] + recur(i,k,arr) +recur(k+1,j,arr);
            mini = min(mini,steps);
        }
        
        return mini;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        
        // return recur(1,N-1,arr);                                // TC : Exponential 
        
        vector<vector<int>> dp(N,vector<int>(N,-1));
        return memo(1,N-1,arr,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends