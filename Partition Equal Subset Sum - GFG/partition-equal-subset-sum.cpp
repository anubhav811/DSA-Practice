//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    bool tab(int N,int target , int arr[]){
        
        vector<vector<bool>> dp(N,vector<bool>(target+1,false));
        
        for(int i=0;i<N;i++)
            dp[i][0] = true;
        
        
        dp[0][0] = true;
        
        for(int i=1;i<N;i++){
            for(int j=1;j<target+1;j++)
            {
                bool pick = (arr[i]<=j) ?  dp[i-1][j-arr[i]] : false;
                bool notPick = dp[i-1][j];
                
                dp[i][j] = pick || notPick;
            }
        }
        
        return dp[N-1][target] ;
        
        
    }
    bool memo(int i,int target , int arr[] , vector<vector<int>> &dp){
        if(target==0)
            return true;
        if(i==0)
            return arr[0] == target;
         
        if(dp[i][target] != -1){
            return dp[i][target];
        }
        
        bool pick = (arr[i]<=target) ? memo(i-1,target-arr[i],arr,dp) : false;
        bool notPick = memo(i-1,target,arr,dp);
        
        return dp[i][target] = pick||notPick;
    }
    bool recur(int i , int target, int arr[]){
        
        if(target==0)
            return true;
        if(i==0)
            return arr[i]==target;
        
        bool pick = (arr[i]<=target) ? recur(i-1,target-arr[i],arr) : false;
        bool notpick = recur(i-1,target,arr);
        
        return pick||notpick;
        
    }
    int equalPartition(int N, int arr[])
    {
        int target = 0;
        for(int i=0;i<N;i++){
            target+=arr[i];
        }
        
        if(target%2==0){
            
            // Recursion                        TC : O(2^N), SC : O(N)
            // return recur(N-1,target/2,arr);
    
            // Memoization                      TC : O(N*target/2), SC : O(N*target/2) + O(N)
            // vector<vector<int>> dp (N,vector<int>(target+1,-1));
            // return memo(N-1,target/2,arr,dp);
    
            // Tabulation                       TC : O(N*target/2), SC : O(N*target/2)
            return tab(N,target/2,arr);
    
            // Space Optimizaton                TC : O(N*target/2), SC : O(target/2)
            // return spaceOpt(N,target/2,arr);
        }
        return 0;
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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends