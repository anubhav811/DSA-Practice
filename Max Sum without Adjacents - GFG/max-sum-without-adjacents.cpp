//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int memo(int i ,int *arr,int n,vector<int> &dp){
	   if(i==0) return arr[i];
	   if(i<0) return 0;
	    
	   if(dp[i]!=-1) return dp[i];
	   int take =  arr[i] + memo(i-2,arr,n,dp);
	   int notTake =  memo(i-1,arr,n,dp) ;
	   
	   return dp[i]=max(take,notTake);
	   
	}
	int findMaxSum(int *arr, int n) {
	    
	   // return recur(n-1,arr, n);
	    
	    vector<int> dp(n,-1);
	    return memo(n-1,arr,n,dp);
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