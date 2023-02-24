//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
    int mod = 1e9+7;
    int recur(int i , int sum , int arr[]){
        
        if(i==0){
            if(sum==0 && arr[0]==0) return 2;
            if(sum==0) return 1;
            return 0;
        }

        int pick = (arr[i]<=sum) ? recur(i-1,sum-arr[i],arr) : 0;
        int notPick = recur(i-1,sum,arr);
        
        return (pick+notPick);
        
    }
    int memo(int i , int sum ,int arr[],vector<vector<int>> &dp){
        
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
       
        if(i==0){
            if(sum==0 && arr[0]==0) return 2;
            if(arr[0]==sum || sum==0) return 1;
            return 0;
        }

        int pick = (arr[i]<=sum) ? memo(i-1,sum-arr[i],arr,dp)%mod : 0;
        int notPick = memo(i-1,sum,arr,dp)%mod;
        
        return dp[i][sum] = (pick+notPick)%mod;
        
        
    }
    int tab(int n,int arr[],int sum){
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
                
                int notPick = dp[i-1][j]%mod;
                int pick = (arr[i]<=j) ? dp[i-1][j-arr[i]]%mod:0;
                
                dp[i][j] = (notPick + pick)%mod;
            }
        }
        
        return dp[n-1][sum]%mod;
    }
    
    int spaceOpt(int n,int arr[],int sum){
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
                
                int notPick = prev[j]%mod;
                int pick = (arr[i]<=j) ? prev[j-arr[i]]%mod:0;
                
                curr[j] = (notPick + pick)%mod;
            }
            prev = curr ;
        }
        
        return prev[sum]%mod;
    }

	public:
	int perfectSum(int arr[], int n, int sum)
	{
	   // Recursion                      TC : O(2^N), SC : O(N)
	   // Doesnt give correct answer because this approach is tailored for positive integer, not 0 and negative
	   // return recur(n-1,sum,arr)%mod;
	   
       // Memoization
	   //vector<vector<int>> dp (n,vector<int>(sum+1,-1));
	   //return memo(n-1,sum,arr,dp);
	   
	   // Tabulation
	   // return tab(n,arr,sum);
	    
	    // SpaceOpt
	    return spaceOpt(n,arr,sum);

    }
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends