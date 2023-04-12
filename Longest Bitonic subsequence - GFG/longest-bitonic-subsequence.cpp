//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	int LongestBitonicSequence(vector<int>A)
	{
	    int n = A.size();
	    
	    vector<int> dp1(n,1);
	    vector<int> dp2(n,1);
	    
	    for(int i=0;i<n;i++){
	        for(int prev=0;prev<i;prev++){
	            
	            if(dp1[prev] + 1 > dp1[i] && A[i]>A[prev]){
	                dp1[i] = dp1[prev] + 1;
	            }
	        }
	    }
	    
	    for(int i=n-1;i>=0;i--){
	        for(int prev=n-1;prev>i;prev--){
	            
	            if(dp2[prev] + 1 > dp2[i] && A[i]>A[prev]){
	                dp2[i] = dp2[prev] + 1;
	            }
	        }
	    }
	    
	    int maxi = 0;
	    for(int i=0;i<n;i++){
	        maxi = max(maxi,dp1[i]+dp2[i]);
	    }
	    
	    return maxi-1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends