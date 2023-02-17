//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int recur(int *arr,int i){
	    
	    // if we are anyhow reaching i = 0 , it means index 1 was not picked (because we dont take adjacent)
	    // so we can pick i=0 element , coz 1 is not picked
	    if(i==0)
	        return arr[i];
	    // However lets say we had reached index =  1 and pick it, then on calling the next recursion we would have options to 
	    // reach 0 and -1
	    // In case of zero we cant pick because it would be adjacent so zero is out of picture, but if we get a -1 or
	    // any other negative value we can simply send back 0 i.e no effect on the sum
	    if(i<0){
	        return 0;
	    }
	    int pick    = arr[i] + recur(arr,i-2);
	    int notpick =    0   + recur(arr,i-1);
	    
	    return max(pick,notpick);
	}
	
	int memo (int *arr,int i,vector<int> &dp){
	    
	    if(i==0)
	        return arr[i];
	    if(i<0)
	        return 0;
	       
	    if(dp[i] != -1){
	        return dp[i];
	    }
	    
        int pick    = arr[i] + recur(arr,i-2);
	    int notpick =    0   + recur(arr,i-1);
	    
	    return dp[i] = max(pick,notpick);	    
	}
	
	int tab(int *arr, int n){
	    vector<int> dp(n+1,-1);
	    
	    dp[0] = arr[0];

	    for(int i=1;i<n;i++){
	         int pick = arr[i];
	         if(i>1)
    	        pick += dp[i-2];
        	 int notpick = 0   + dp[i-1];   
        	 
        	 dp[i] = max(pick,notpick);
	    }
	    
	    return dp[n-1];
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	    
	    // Recursion TLE
	    // array and index passed 
	   // return recur(arr,n-1);
	    
	    // Memoization TLE
	    // array ,dp and index passed 
	   // vector<int> dp(n+1,-1);
	   // return memo(arr,n-1,dp);
	   
	   // DP Tabulation 
	   // array and size passed
	   return tab(arr,n);
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends