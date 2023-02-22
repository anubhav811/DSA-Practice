//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool memo(int i,int sum , int arr[] , vector<vector<int>> &dp){
        if(sum==0)
            return true;
        if(i==0)
            return arr[0] == sum;
         
        if(dp[i][sum] != -1){
            return dp[i][sum];
        }
        
        bool pick = (arr[i]<=sum) ? memo(i-1,sum-arr[i],arr,dp) : false;
        bool notPick = memo(i-1,sum,arr,dp);
        
        return dp[i][sum] = pick||notPick;
    }
    bool recur(int i , int sum, int arr[]){
        
        if(sum==0)
            return true;
        if(i==0)
            return arr[i]==sum;
        
        bool pick = (arr[i]<=sum) ? recur(i-1,sum-arr[i],arr) : false;
        bool notpick = recur(i-1,sum,arr);
        
        return pick||notpick;
        
    }
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        
        if(sum%2==0){
            
            // Recursion                        TC : O(2^N), SC : O(N)
            // return recur(N-1,sum/2,arr);
    
            // Memoization                      TC : O(N*target/2), SC : O(N*target/2) + O(N)
            vector<vector<int>> dp (N,vector<int>(sum+1,-1));
            return memo(N-1,sum/2,arr,dp);
    
            // Tabulation                       TC : O(N*target/2), SC : O(N*target/2)
            // return tab(N,sum/2,arr);
    
            // Space Optimizaton                TC : O(N*target/2), SC : O(target/2)
            // return spaceOpt(N,sum/2,arr);
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