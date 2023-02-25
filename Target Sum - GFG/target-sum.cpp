//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int recur(int i , int sum , vector<int> &arr){
        
        if(i==0){
            if(sum==0 && arr[0]==0) return 2;
            if(sum==0) return 1;
            return 0;
        }

        int pick = (arr[i]<=sum) ? recur(i-1,sum-arr[i],arr) : 0;
        int notPick = recur(i-1,sum,arr);
        
        return (pick+notPick);
        
    }
    int memo(int i , int sum ,vector<int> &arr,vector<vector<int>> &dp){
        
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
       
        if(i==0){
            if(sum==0 && arr[0]==0) return 2;
            if(arr[0]==sum || sum==0) return 1;
            return 0;
        }

        int pick = (arr[i]<=sum) ? memo(i-1,sum-arr[i],arr,dp) : 0;
        int notPick = memo(i-1,sum,arr,dp);
        
        return dp[i][sum] = (pick+notPick);
        
        
    }
    int tab(int n,vector<int> &arr,int sum){
        vector<vector<int>> dp(n,vector<int>(sum+1,0));
        
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
                dp[i][0] = 2;
            else
                dp[i][0] = 1;
        }
        if (arr[0] <= sum && arr[0] != 0)
            dp[0][arr[0]] = 1;

        for(int i=1;i<n;i++){
            for(int j=0;j<=sum;j++){
                
                int notPick = dp[i-1][j];
                int pick = (arr[i]<=j) ? dp[i-1][j-arr[i]]:0;
                
                dp[i][j] = (notPick + pick);
            }
        }
        
        return dp[n-1][sum];
    }

    int spaceOpt(int n,vector<int> &arr,int sum){
        vector<int> prev(sum+1,0), curr(sum+1,0);
        
            if (arr[0] == 0){
                prev[0] = 2;
            }
            else{
                prev[0] = 1;
            }
        if (arr[0] <= sum && arr[0] != 0)
            prev[arr[0]] = 1;
            
        curr = prev ;
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum;j++){
                
                int notPick = prev[j];
                int pick = (arr[i]<=j) ? prev[j-arr[i]]:0;
                
                curr[j] = (notPick + pick);
            }
            prev = curr ;
        }
        
        return prev[sum];
    }
    int findTargetSumWays(vector<int>&A ,int target) {
        //Your code here
        
        int n = A.size();
    
        int totSum = 0;
        for(auto it:A){
            totSum += it;
        }
        
        if (totSum < abs(target) || (totSum - target) % 2) {
            return 0;
        }

        int sum = (totSum+target)/2;
        
        // Recursion                      TC : O(2^N), SC : O(N)
	   // return recur(n-1,sum,A);
	   
       // Memoization
	   // vector<vector<int>> dp (n,vector<int>(target+1,-1));
	   // return memo(n-1,sum,A,dp);
	   
	   // Tabulation
	   // return tab(n,A,sum);
	    
	    // SpaceOpt
	    return spaceOpt(n,A,sum);       
	    
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends