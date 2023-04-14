#include<bits/stdc++.h>
using namespace std;
int main()
{

    return 0;
}
class Solution{
	public:
	
    // TC: O(N*N)  SC:O(2*N)
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
